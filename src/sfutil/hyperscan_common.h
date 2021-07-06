/*
** Copyright (c) 2017, Intel Corporation.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License Version 2 as
** published by the Free Software Foundation.  You may not use, modify or
** distribute this program under any other version of the GNU General
** Public License.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/

#ifndef SNORT_HYPERSCAN_COMMON_H
#define SNORT_HYPERSCAN_COMMON_H

#include <hs.h>

// Scratch space for Hyperscan MPSE matcher.
hs_scratch_t *hs_mpse_build_scratch;
hs_scratch_t *hs_mpse_scan_scratch;

// Scratch space for Hyperscan sp_pattern_match (single) matcher.
hs_scratch_t *hs_single_build_scratch;
hs_scratch_t *hs_single_scan_scratch;

// Scratch space for Hyperscan PCRE prefilter.
hs_scratch_t *hs_pcre_build_scratch;
hs_scratch_t *hs_pcre_scan_scratch;

void HyperscanActivate(void);
void HyperscanFreeGlobalContext(void);

#endif // SNORT_HYPERSCAN_COMMON_H