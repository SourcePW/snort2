/****************************************************************************
 * Copyright (C) 2014-2021 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2008-2013 Sourcefire, Inc.
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
 * Handles processing of events generated by the preprocessor.
 *
 * 8/17/2008 - Initial implementation ... Todd Wease <twease@sourcefire.com>
 *
 ****************************************************************************/

#ifndef _DCE2_EVENT_H_
#define _DCE2_EVENT_H_

#include "dce2_session.h"
#include "dce2_config.h"
#include "snort_debug.h"
#include "dcerpc.h"
#include "sf_types.h"

/********************************************************************
 * Macros
 ********************************************************************/
#define GENERATOR_DCE2  133

/********************************************************************
 * Externs
 ********************************************************************/
extern char *dce2_pdu_types[DCERPC_PDU_TYPE__MAX];

/********************************************************************
 * Enumerations
 ********************************************************************/
/* Since this is mirrored in generators.h via #defines, any
 * additions to this should go at the end, just before
 * DCE2_EVENT__MAX.  It is important the the sids stay the
 * same in generators.h as these are also in gen-msg.map */
typedef enum _DCE2_Event
{
    DCE2_EVENT__NO_EVENT = 0,
    DCE2_EVENT__MEMCAP,
    DCE2_EVENT__SMB_BAD_NBSS_TYPE,
    DCE2_EVENT__SMB_BAD_TYPE,
    DCE2_EVENT__SMB_BAD_ID,
    DCE2_EVENT__SMB_BAD_WCT,
    DCE2_EVENT__SMB_BAD_BCC,
    DCE2_EVENT__SMB_BAD_FORMAT,
    DCE2_EVENT__SMB_BAD_OFF,
    DCE2_EVENT__SMB_TDCNT_ZERO,
    DCE2_EVENT__SMB_NB_LT_SMBHDR,
    DCE2_EVENT__SMB_NB_LT_COM,
    DCE2_EVENT__SMB_NB_LT_BCC,
    DCE2_EVENT__SMB_NB_LT_DSIZE,
    DCE2_EVENT__SMB_TDCNT_LT_DSIZE,
    DCE2_EVENT__SMB_DSENT_GT_TDCNT,
    DCE2_EVENT__SMB_BCC_LT_DSIZE,
    DCE2_EVENT__SMB_INVALID_DSIZE,
    DCE2_EVENT__SMB_EXCESSIVE_TREE_CONNECTS,
    DCE2_EVENT__SMB_EXCESSIVE_READS,
    DCE2_EVENT__SMB_EXCESSIVE_CHAINING,
    DCE2_EVENT__SMB_MULT_CHAIN_SS,
    DCE2_EVENT__SMB_MULT_CHAIN_TC,
    DCE2_EVENT__SMB_CHAIN_SS_LOGOFF,
    DCE2_EVENT__SMB_CHAIN_TC_TDIS,
    DCE2_EVENT__SMB_CHAIN_OPEN_CLOSE,
    DCE2_EVENT__SMB_INVALID_SHARE,
    DCE2_EVENT__CO_BAD_MAJ_VERSION,
    DCE2_EVENT__CO_BAD_MIN_VERSION,
    DCE2_EVENT__CO_BAD_PDU_TYPE,
    DCE2_EVENT__CO_FLEN_LT_HDR,
    DCE2_EVENT__CO_FLEN_LT_SIZE,
    DCE2_EVENT__CO_ZERO_CTX_ITEMS,
    DCE2_EVENT__CO_ZERO_TSYNS,
    DCE2_EVENT__CO_FRAG_LT_MAX_XMIT_FRAG,
    DCE2_EVENT__CO_FRAG_GT_MAX_XMIT_FRAG,
    DCE2_EVENT__CO_ALTER_CHANGE_BYTE_ORDER,
    DCE2_EVENT__CO_FRAG_DIFF_CALL_ID,
    DCE2_EVENT__CO_FRAG_DIFF_OPNUM,
    DCE2_EVENT__CO_FRAG_DIFF_CTX_ID,
    DCE2_EVENT__CL_BAD_MAJ_VERSION,
    DCE2_EVENT__CL_BAD_PDU_TYPE,
    DCE2_EVENT__CL_DATA_LT_HDR,
    DCE2_EVENT__CL_BAD_SEQ_NUM,
    DCE2_EVENT__SMB_V1,
    DCE2_EVENT__SMB_V2,
    DCE2_EVENT__SMB_INVALID_BINDING,
    DCE2_EVENT__SMB2_EXCESSIVE_COMPOUNDING,
    DCE2_EVENT__SMB_DCNT_ZERO,
    DCE2_EVENT__SMB_DCNT_MISMATCH,
    DCE2_EVENT__SMB_MAX_REQS_EXCEEDED,
    DCE2_EVENT__SMB_REQS_SAME_MID,
    DCE2_EVENT__SMB_DEPR_DIALECT_NEGOTIATED,
    DCE2_EVENT__SMB_DEPR_COMMAND_USED,
    DCE2_EVENT__SMB_UNUSUAL_COMMAND_USED,
    DCE2_EVENT__SMB_INVALID_SETUP_COUNT,
    DCE2_EVENT__SMB_MULTIPLE_NEGOTIATIONS,
    DCE2_EVENT__SMB_EVASIVE_FILE_ATTRS,
    DCE2_EVENT__SMB_INVALID_FILE_OFFSET,
    DCE2_EVENT__SMB_BAD_NEXT_COMMAND_OFFSET,
    DCE2_EVENT__MAX

} DCE2_Event;

/********************************************************************
 * Structures
 ********************************************************************/
typedef struct _DCE2_EventNode
{
    DCE2_EventFlag eflag;
    DCE2_Event event;
    char *format;

} DCE2_EventNode;

/********************************************************************
 * Public Function Prototypes
 ********************************************************************/
void DCE2_EventsInit(void);
void DCE2_Alert(DCE2_SsnData *, DCE2_Event, ...);
void DCE2_EventsFree(void);

/********************************************************************
 * Inline Function Prototypes
 ********************************************************************/
static inline int DCE2_SsnAlerted(DCE2_SsnData *, DCE2_Event);

/******************************************************************
 * Function: DCE2_SsnAlerted()
 *
 * Checks to see if we have already generated an alert on this
 * session for the event type passed in.
 *
 * Arguments:
 *  DCE2_SsnData *
 *      The session data structure.
 *  DCE2_Event
 *      The event to check for.
 *
 * Returns:
 *  int
 *      1 if we have already alerted for this event type on this
 *          session.
 *      0 if we have not alerted for this event type on this
 *          session.
 *
 ******************************************************************/
static inline int DCE2_SsnAlerted(DCE2_SsnData *sd, DCE2_Event e)
{
    if (sd->alert_mask & (1 << e)) return 1;
    return 0;
}

#endif  /* _DCE2_EVENT_H_ */

