# $NetBSD: buildlink3.mk,v 1.2 2014/05/16 20:47:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-tdfa

.if !defined(HS_REGEX_TDFA_BUILDLINK3_MK)
HS_REGEX_TDFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.1
BUILDLINK_PKGSRCDIR.hs-regex-tdfa?=	../../wip/hs-regex-tdfa

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.include "../../wip/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_TDFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-tdfa
