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

#include "hyperscan_common.h"

hs_scratch_t *hs_mpse_build_scratch = NULL;
hs_scratch_t *hs_mpse_scan_scratch = NULL;

hs_scratch_t *hs_single_build_scratch = NULL;
hs_scratch_t *hs_single_scan_scratch = NULL;

hs_scratch_t *hs_pcre_build_scratch = NULL;
hs_scratch_t *hs_pcre_scan_scratch = NULL;

static void ActivateScratch(hs_scratch_t **build_scratch,
                            hs_scratch_t **scan_scratch) {
    hs_free_scratch(*scan_scratch);
    *scan_scratch = *build_scratch;
    *build_scratch = NULL;
}

void HyperscanActivate(void) {
    ActivateScratch(&hs_mpse_build_scratch, &hs_mpse_scan_scratch);
    ActivateScratch(&hs_single_build_scratch, &hs_single_scan_scratch);
    ActivateScratch(&hs_pcre_build_scratch, &hs_pcre_scan_scratch);
}

void HyperscanFreeGlobalContext(void) {
    hs_free_scratch(hs_mpse_build_scratch);
    hs_mpse_build_scratch = NULL;
    hs_free_scratch(hs_mpse_scan_scratch);
    hs_mpse_scan_scratch = NULL;

    hs_free_scratch(hs_single_build_scratch);
    hs_single_build_scratch = NULL;
    hs_free_scratch(hs_single_scan_scratch);
    hs_single_scan_scratch = NULL;

    hs_free_scratch(hs_pcre_build_scratch);
    hs_pcre_build_scratch = NULL;
    hs_free_scratch(hs_pcre_scan_scratch);
    hs_pcre_scan_scratch = NULL;
}