# $NetBSD: buildlink3.mk,v 1.4 2009/05/21 04:52:46 phonohawk Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.1nb1
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../wip/hs-regex-base

.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
