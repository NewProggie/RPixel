// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#include "display/surface.h"

namespace rpixel {
namespace display {

cairo_surface_t* CreateCairoSurface(int width, int height) {
    auto* surface =
        cairo_image_surface_create(CAIRO_FORMAT_RGB16_565, width, height);

    return surface;
}
}
}
