/*******************************************************************************
 *
 * TRIQS: a Toolbox for Research in Interacting Quantum Systems
 *
 * Copyright (C) 2013 by O. Parcollet
 *
 * TRIQS is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 *
 * TRIQS is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * TRIQS. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#ifndef TRIQS_GFS_ALL_H
#define TRIQS_GFS_ALL_H

#define TRIQS_GF_INCLUDED

#include "./gfs/gf_classes.hpp"

#include <triqs/gfs/imtime.hpp>
#include <triqs/gfs/imfreq.hpp>
#include <triqs/gfs/retime.hpp>
#include <triqs/gfs/refreq.hpp>
#include <triqs/gfs/legendre.hpp>
#include <triqs/gfs/bz.hpp>
#include <triqs/gfs/cyclic_lattice.hpp>
#include <triqs/gfs/product.hpp>
#include <triqs/gfs/curry.hpp>
#include <triqs/gfs/singularity/m_tail.hpp>

#include <triqs/gfs/block.hpp>
#include <triqs/gfs/block2.hpp>

#include <triqs/gfs/impl/map.hpp>
#include <triqs/gfs/impl/block_gf_iterator.hpp>

#include <triqs/gfs/transform/fourier_matsubara.hpp>
#include <triqs/gfs/transform/fourier_real.hpp>
#include <triqs/gfs/transform/fourier_lattice.hpp>
#include <triqs/gfs/transform/legendre_matsubara.hpp>
#endif

