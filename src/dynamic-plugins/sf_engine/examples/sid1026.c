/*
 * VRT RULES
 *
 * Copyright (C) 2014-2021 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2005-2013 Sourcefire, Inc.
 *
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "sf_snort_plugin_api.h"
#include "detection_lib_meta.h"

/* declare detection functions */
int rule1026eval(void *p);

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
/* flow for sid 1026 */
/* flow:established, to_server; */
static FlowFlags rule1026flow1 =
{
    FLOW_ESTABLISHED|FLOW_TO_SERVER
};

static RuleOption rule1026option1 =
{
    OPTION_TYPE_FLOWFLAGS,
    { &rule1026flow1 }
};

/* content for sid 1026 */
// content:"|0A|.pl", payload uri, nocase;
static ContentInfo rule1026content2 =
{
    (u_int8_t *)"|0A|.pl", /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_NOCASE|CONTENT_BUF_URI, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0, /* increment length */
    0,                      /* holder for fp offset */
    0,                      /* holder for fp length */
    0,                      /* holder for fp only */
    NULL, // offset_refId
    NULL, // depth_refId
    NULL, // offset_location
    NULL  // depth_location
};

static RuleOption rule1026option2 =
{
    OPTION_TYPE_CONTENT,
    { &rule1026content2 }
};


/* references for sid 1026 */
static RuleReference *rule1026refs[] =
{
    NULL
};

RuleOption *rule1026options[] =
{
    &rule1026option1,
    &rule1026option2,
    NULL
};

Rule rule1026 = {

   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_TCP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "any", /* SRCPORT   */
       0, /* DIRECTION */
       "$HTTP_SERVERS", /* DSTIP     */
       "$HTTP_PORTS", /* DSTPORT   */
   },
   /* metadata */
   {
       RULE_GID,  /* genid (HARDCODED!!!) */
       1026, /* sigid */
       9, /* revision */

       "web-application-attack", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "WEB-IIS perl-browse newline attempt",     /* message */
       rule1026refs, /* ptr to references */
       NULL /* Meta data */
   },
   rule1026options, /* ptr to rule options */
    NULL,                               /* Use internal eval func */
    0,                                  /* Not initialized */
    0,                                  /* Rule option count, used internally */
    0,                                  /* Flag with no alert, used internally */
    NULL /* ptr to internal data... setup during rule registration */
};



/* detection functions */

int rule1026eval(void *p) {
    /* cursors, formally known as doe_ptr */
    const u_int8_t *cursor_uri = 0;

    /* flow:established, to_server; */
    if (checkFlow(p, rule1026options[0]->option_u.flowFlags)) {
        // content:"|0A|.pl", payload uri, nocase;
        if (contentMatch(p, rule1026options[1]->option_u.content, &cursor_uri) > 0) {
            return RULE_MATCH;
        }
    }
    return RULE_NOMATCH;
}