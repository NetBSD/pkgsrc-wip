# $NetBSD: buildlink3.mk,v 1.1 2014/02/06 15:12:17 fhajny Exp $

BUILDLINK_TREE+=	spidermonkey24

.if !defined(SPIDERMONKEY24_BUILDLINK3_MK)
SPIDERMONKEY24_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.spidermonkey24+=	spidermonkey24>=24.2.0
BUILDLINK_PKGSRCDIR.spidermonkey24?=	../../wip/spidermonkey24

.include "../../devel/nspr/buildlink3.mk"
.endif	# SPIDERMONKEY24_BUILDLINK3_MK

BUILDLINK_TREE+=	-spidermonkey24
