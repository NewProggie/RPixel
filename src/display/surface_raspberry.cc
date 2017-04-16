// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#include "display/surface.h"
#include <cairo/cairo.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>

namespace rpixel {
namespace display {

namespace {

struct CairoLinuxFBDevice {
    int fb_fd;
    unsigned char *fb_data;
    long fb_screensize;
    struct fb_var_screeninfo var_info;
    struct fb_fix_screeninfo fix_info;
};

void cairo_linuxfb_surface_destroy(void *device) {
    auto *dev = static_cast<CairoLinuxFBDevice *>(device);

    if (dev == nullptr) { return; }
    munmap(dev->fb_data, dev->fb_screensize);
    close(dev->fb_fd);
}
}

cairo_surface_t *CreateCairoSurface() {
    auto device = make_unique<CairoLinuxFBDevice>();

    // Open the file for reading and writing
    device->fb_fd = open("/dev/fb1", O_RDWR);
    if (device->fb_fd == -1) {
        std::cerr << "Error: cannot open framebuffer device\n";
        std::exit(1);
    }

    // Get variable screen information
    if (ioctl(device->fb_fd, FBIOGET_VSCREENINFO, &device->var_info) == -1) {
        std::cerr << "Error reading variable information\n";
        std::exit(3);
    }

    // Figure out the size of the screen in bytes
    device->fb_screensize = device->var_info.xres * device->var_info.yres *
                            device->var_info.bits_per_pixel / 8;

    // Map the device to memory
    device->fb_data = static_cast<unsigned char *>(
        mmap(0, device->fb_screensize, PROT_READ | PROT_WRITE, MAP_SHARED,
             device->fb_fd, 0));
    if (reinterpret_cast<int>(device->fb_data) == -1) {
        std::cerr << "Error: failed to map framebuffer device to memory\n";
        std::exit(4);
    }

    // Get fixed screen information
    if (ioctl(device->fb_fd, FBIOGET_FSCREENINFO, &device->fix_info) == -1) {
        std::cerr << "Error reading fixed information\n";
        std::exit(2);
    }

    auto *surface = cairo_image_surface_create_for_data(
        device->fb_data, CAIRO_FORMAT_RGB16_565, device->var_info.xres,
        device->var_info.yres,
        cairo_format_stride_for_width(CAIRO_FORMAT_RGB16_565,
                                      device->var_info.xres));
    cairo_surface_set_user_data(surface, nullptr, device.get(),
                                &cairo_linuxfb_surface_destroy);

    return surface;
}
}
}