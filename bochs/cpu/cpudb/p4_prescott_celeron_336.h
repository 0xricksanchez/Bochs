/////////////////////////////////////////////////////////////////////////
// $Id$
/////////////////////////////////////////////////////////////////////////
//
//   Copyright (c) 2011 Stanislav Shwartsman
//          Written by Stanislav Shwartsman [sshwarts at sourceforge net]
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA B 02110-1301 USA
//
/////////////////////////////////////////////////////////////////////////

#ifndef BX_P4_PSC_CELERON_336_CPUID_DEFINITIONS_H
#define BX_P4_PSC_CELERON_336_CPUID_DEFINITIONS_H

#if BX_SUPPORT_X86_64

#include "cpu/cpuid.h"

class p4_prescott_celeron_336_t : public bx_cpuid_t {
public:
  p4_prescott_celeron_336_t(BX_CPU_C *cpu);
  virtual ~p4_prescott_celeron_336_t() {}

  // return CPU name
  virtual const char *get_name(void) const { return "p4_prescott_celeron_336"; }

  virtual Bit32u get_isa_extensions_bitmask(void) const;
  virtual Bit32u get_cpu_extensions_bitmask(void) const;

  virtual void get_cpuid_leaf(Bit32u function, Bit32u subfunction, cpuid_function_t *leaf) const;

  virtual void dump_cpuid(void) const;

#if BX_CPU_LEVEL >= 5
  virtual int rdmsr(Bit32u index, Bit64u *msr) { return -1; }
  virtual int wrmsr(Bit32u index, Bit64u  msr) { return -1; }
#endif

private:
#if BX_SUPPORT_SMP
  unsigned nprocessors;
  unsigned ncores;
  unsigned nthreads;
#endif

  void get_std_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_2(cpuid_function_t *leaf) const;
  void get_std_cpuid_leaf_3(cpuid_function_t *leaf) const;

  void get_ext_cpuid_leaf_0(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_1(cpuid_function_t *leaf) const;
  void get_ext_cpuid_brand_string_leaf(Bit32u function, cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_5(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_6(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_7(cpuid_function_t *leaf) const;
  void get_ext_cpuid_leaf_8(cpuid_function_t *leaf) const;
};

extern bx_cpuid_t *create_p4_prescott_celeron_336_cpuid(BX_CPU_C *cpu);

#endif // BX_SUPPORT_X86_64

#endif
