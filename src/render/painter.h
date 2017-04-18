// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_PAINTER_H
#define RPIXEL_PAINTER_H

#include <cairo/cairo.h>

namespace rpixel {
namespace render {

class Painter {
 public:
  Painter(cairo_t* cr, int block_size);
  void drawLogoGMail(int start_x, int start_y);

 private:
  cairo_t *cr_;
  int bs_;

};
}
}

#endif // RPIXEL_PAINTER_H
