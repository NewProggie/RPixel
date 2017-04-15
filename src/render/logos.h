// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_RENDER_LOGOS_H_
#define RPIXEL_RENDER_LOGOS_H_

#include <cairo/cairo.h>

namespace rpixel {

void DrawGMailLogo(cairo_t* cr, int bs, int start_x, int start_y) {

    const int logo_len_x = 8 * bs;
    const int logo_len_y = 6 * bs;
    int offset_m         = start_y;
    for (int x = start_x; x < start_x + logo_len_x; x += bs) {
        for (int y = start_y; y < start_y + logo_len_y; y += bs) {
            // Draw background
            cairo_set_source_rgb(cr, 1.0, 1.0, 1.0);
            cairo_rectangle(cr, x, y, bs - 1, bs - 1);

            cairo_fill(cr);
            // Draw edges
            cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);
            cairo_rectangle(cr, start_x, y, bs - 1, bs - 1);
            cairo_rectangle(cr, start_x + logo_len_x - bs, y, bs - 1, bs - 1);
            cairo_fill(cr);
        }
        // Draw center of M
        cairo_rectangle(cr, x, offset_m, bs - 1, bs - 1);
        cairo_rectangle(cr, x, offset_m + bs, bs - 1, bs - 1);
        cairo_fill(cr);
        if (start_x + bs > x || x >= start_x + logo_len_x - 2 * bs) {
            continue;
        } else if (x < start_x + logo_len_x / 2 - bs) {
            offset_m += bs;
        } else if (x > start_x + logo_len_x / 2 - bs) {
            offset_m -= bs;
        }
    }
}
}

#endif // RPIXEL_RENDER_LOGOS_H_
