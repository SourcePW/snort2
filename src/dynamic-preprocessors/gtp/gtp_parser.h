/****************************************************************************
 * Copyright (C) 2014-2021 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2011-2013 Sourcefire, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 2 as
 * published by the Free Software Foundation.  You may not use, modify or
 * distribute this program under any other version of the GNU General
 * Public License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 ****************************************************************************
 * Provides convenience functions for parsing and querying configuration.
 *
 * 2/17/2011 - Initial implementation ... Hui Cao <hcao@sourcefire.com>
 *
 ****************************************************************************/

#ifndef _GTP_PARSER_H_
#define _GTP_PARSER_H_

#include "sfPolicyUserData.h"
#include "snort_bounds.h"
#include "gtp_debug.h"
#include "spp_gtp.h"

int gtp_parse(GTPMsg *, const uint8_t *, uint16_t);
void gtp_cleanInfoElements(void);
#endif
