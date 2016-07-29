# $NetBSD: buildlink3.mk,v 1.1 2014/02/06 15:12:17 fhajny Exp $

BUILDLINK_TREE+=	spidermonkey31

.if !defined(SPIDERMONKEY31_BUILDLINK3_MK)
SPIDERMONKEY31_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey31+=	spidermonkey31>=31.2.0
BUILDLINK_PKGSRCDIR.spidermonkey31?=	../../wip/spidermonkey31

.include "../../devel/nspr/buildlink3.mk"
.endif	# SPIDERMONKEY31_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey31
