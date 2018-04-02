/*******************************************************************************
 *
 * TRIQS: a Toolbox for Research in Interacting Quantum Systems
 *
 * Copyright (C) 2012 by M. Ferrero, O. Parcollet
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
#pragma once
#include <triqs/utility/arithmetic_ops_by_cast.hpp>
#include <triqs/utility/iterator_facade.hpp>

namespace triqs {
namespace gfs {

 using dcomplex = std::complex<double>;

 namespace tag {
  struct composite {};
  struct mesh_point {};
 }

 /** The statistics : Boson or Fermion
  */
 enum statistic_enum {
  Boson,
  Fermion
 };

 // Interpolation policies
 namespace interpol_t {
  struct None {};
  struct Product {};
  struct Linear1d {};
  struct Linear2d {};
 }

 // The mesh for each Var
 template <typename Var> struct gf_mesh;

 // The mesh point for each mesh
 template <typename MeshType> struct mesh_point;

 // FIXME : remove boost !
 template<typename MeshType>
  class mesh_pt_generator : 
   public triqs::utility::iterator_facade< mesh_pt_generator<MeshType>, typename MeshType::mesh_point_t , std::forward_iterator_tag,
   typename MeshType::mesh_point_t const & > {
    friend class triqs::utility::iterator_facade< mesh_pt_generator<MeshType>, typename MeshType::mesh_point_t , std::forward_iterator_tag, typename MeshType::mesh_point_t const & >;
    MeshType const * mesh;
    size_t u;
    typename MeshType::mesh_point_t pt;
    typename MeshType::mesh_point_t const & dereference() const { return pt;}
    bool equal(mesh_pt_generator const & other) const { return ((other.u==u) );}
    // do NOT check = of mesh, otherwise e.g. block iterator does not work (infinite loop...)
    //bool equal(mesh_pt_generator const & other) const { return ((mesh == other.mesh) && (other.u==u) );}
    public:
    mesh_pt_generator(): mesh(nullptr), u(0) {}
    mesh_pt_generator( MeshType const * m, bool atEnd = false): mesh(m), u(atEnd ? m->size(): 0), pt(*m) {}
    void increment() { ++u; pt.advance(); }
    bool at_end() const { return (u>=mesh->size());}
    typename MeshType::domain_t::point_t to_point() const { return pt;}
    mesh_pt_generator& operator+=(int n) {
     for (int i = 0; i < n; ++i) increment();
     return *this;
    }
    friend mesh_pt_generator operator+(mesh_pt_generator lhs, int n) { return lhs += n; }
   };
 
 
 // A little vehicle for the ref of a mesh, when infty point should be ignored
 template<typename MeshType> struct mesh_without_infty{
  MeshType const & m;

  using domain_t = typename MeshType::domain_t;
  using mesh_point_t = mesh_point<mesh_without_infty>;
  using const_iterator = mesh_pt_generator<mesh_without_infty>;
  const_iterator begin() const { return const_iterator(this); }
  const_iterator end() const { return const_iterator(this, true); }
  const_iterator cbegin() const { return const_iterator(this); }
  const_iterator cend() const { return const_iterator(this, true); }
 };


}}
