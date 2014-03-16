# $NetBSD: buildlink3.mk,v 1.1 2014/03/16 12:16:14 szptvlfn Exp $

BUILDLINK_TREE+=	hs-polyparse

.if !defined(HS_POLYPARSE_BUILDLINK3_MK)
HS_POLYPARSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-polyparse+=	hs-polyparse>=1.9
BUILDLINK_PKGSRCDIR.hs-polyparse?=	../../wip/hs-polyparse

.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_POLYPARSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-polyparse
