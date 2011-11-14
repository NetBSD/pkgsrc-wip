# $NetBSD: buildlink3.mk,v 1.2 2011/11/14 10:05:00 phonohawk Exp $

BUILDLINK_TREE+=	hs-ascii

.if !defined(HS_ASCII_BUILDLINK3_MK)
HS_ASCII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ascii+=	hs-ascii>=0.0.3
BUILDLINK_PKGSRCDIR.hs-ascii?=	../../wip/hs-ascii

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-case-insensitive/buildlink3.mk"
.include "../../wip/hs-text/buildlink3.mk"
.endif	# HS_ASCII_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ascii
