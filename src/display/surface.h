// Copyright (c) 2017, Kai Wolf. All rights reserved.
// Use of this source code is governed by a Apache license that can be
// found in the LICENSE file in the top directory.

#ifndef RPIXEL_SURFACE_H
#define RPIXEL_SURFACE_H

#include <cairo/cairo.h>

namespace rpixel {
namespace display {

cairo_surface_t* CreateCairoSurface(int width, int height);

}
}

#endif // RPIXEL_SURFACE_H
