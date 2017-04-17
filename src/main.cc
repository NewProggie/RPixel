// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#include <cairo/cairo.h>
#include "base/utils.h"
#include "display/surface.h"
#include "render/logos.h"

int main(int argc, char *argv[]) {
    auto *surface = rpixel::display::CreateCairoSurface();
    SCOPE_EXIT(cairo_surface_destroy(surface));
    auto *cr = cairo_create(surface);
SCOPE_EXIT(cairo_destroy(cr));

    // Clear canvas before drawing
    cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
    cairo_paint(cr);
    cairo_set_operator(cr, CAIRO_OPERATOR_OVER);

    constexpr auto bs = 10;
    rpixel::DrawGMailLogo(cr, bs, 3*bs, 4*bs);
    cairo_surface_write_to_png (surface, "rpixel.png");

    return 0;
}

