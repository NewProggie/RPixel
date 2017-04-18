// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#include "painter.h"

namespace rpixel {
namespace render {

Painter::Painter(cairo_t *cr, int block_size) : cr_(cr), bs_(block_size) {}

void Painter::drawLogoGMail(int start_x, int start_y) {

    const int logo_len_x = 8 * bs_;
    const int logo_len_y = 6 * bs_;
    start_x *= bs_;
    start_y *= bs_;
    int offset_m         = start_y;
    for (int x = start_x; x < start_x + logo_len_x; x += bs_) {
        for (int y = start_y; y < start_y + logo_len_y; y += bs_) {
            // Draw background
            cairo_set_source_rgb(cr_, 1.0, 1.0, 1.0);
            cairo_rectangle(cr_, x, y, bs_ - 1, bs_ - 1);

            cairo_fill(cr_);
            // Draw edges
            cairo_set_source_rgb(cr_, 1.0, 0.0, 0.0);
            cairo_rectangle(cr_, start_x, y, bs_ - 1, bs_ - 1);
            cairo_rectangle(cr_, start_x + logo_len_x - bs_, y, bs_ - 1,
                            bs_ - 1);
            cairo_fill(cr_);
        }
        // Draw center of M
        cairo_rectangle(cr_, x, offset_m, bs_ - 1, bs_ - 1);
        cairo_rectangle(cr_, x, offset_m + bs_, bs_ - 1, bs_ - 1);
        cairo_fill(cr_);
        if (start_x + bs_ > x || x >= start_x + logo_len_x - 2 * bs_) {
            continue;
        } else if (x < start_x + logo_len_x / 2 - bs_) {
            offset_m += bs_;
        } else if (x > start_x + logo_len_x / 2 - bs_) {
            offset_m -= bs_;
        }
    }
}
}
}