# $NetBSD: buildlink3.mk,v 1.6 2011/12/04 12:52:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.2
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../wip/hs-regex-base

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
