// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#include "base/cmdline_flags.h"
#include "base/logging.h"
#include "base/utils.h"
#include "display/surface.h"
#include "render/painter.h"
#include <cairo/cairo.h>

namespace rpixel {

DEFINE_int32(block_size, 10, "Pixel block size");
DEFINE_int32(verbosity, rpixel::base::INFO, "Level of verbose logging output");

namespace internal {

void PrintUsageAndExit() {
    fprintf(stdout,
            "run_pixel"
            " [--block_size=<block_size>]\n"
            "          [--v=<verbosity>]\n");
    std::exit(0);
}

void ParseCmdLineFlags(int argc, char *argv[]) {
    using namespace rpixel;
    for (int idx = 1; idx < argc; ++idx) {
        if (base::ParseInt32Flag(argv[idx], "block_size", &FLAGS_block_size) ||
            base::ParseInt32Flag(argv[idx], "v", &FLAGS_verbosity)) {
            for (int jdx = idx; jdx != argc; jdx++) {
                argv[jdx] = argv[jdx + 1];
            }
            --(argc);
            --idx;
        } else if (base::IsFlag(argv[idx], "help")) {
            PrintUsageAndExit();
        }
    }
}
}
}

int main(int argc, char *argv[]) {
    using namespace rpixel;
    internal::ParseCmdLineFlags(argc, argv);
    base::internal::SetLoggingLevel(FLAGS_verbosity);
    LOGGING(base::INFO) << "Using pixel blocksize " << FLAGS_block_size << "\n";

    auto *surface = rpixel::display::CreateCairoSurface(320, 240);
    SCOPE_EXIT(cairo_surface_destroy(surface));

    auto *cr = cairo_create(surface);
    SCOPE_EXIT(cairo_destroy(cr));

    // Clear canvas before drawing
    cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
    cairo_paint(cr);
    cairo_set_operator(cr, CAIRO_OPERATOR_OVER);

    rpixel::render::Painter painter{cr, FLAGS_block_size};
    painter.drawLogoGMail(1, 5);

    cairo_surface_write_to_png(surface, "rpixel.png");

    return 0;
}
