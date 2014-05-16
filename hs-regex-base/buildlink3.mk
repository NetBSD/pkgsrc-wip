# $NetBSD: buildlink3.mk,v 1.7 2014/05/16 20:47:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-base

.if !defined(HS_REGEX_BASE_BUILDLINK3_MK)
HS_REGEX_BASE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-base+=	hs-regex-base>=0.93.2
BUILDLINK_PKGSRCDIR.hs-regex-base?=	../../wip/hs-regex-base

.include "../../devel/hs-mtl/buildlink3.mk"
.endif	# HS_REGEX_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-base
