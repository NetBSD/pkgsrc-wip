# $NetBSD: buildlink3.mk,v 1.5 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-regex-tdfa

.if !defined(HS_REGEX_TDFA_BUILDLINK3_MK)
HS_REGEX_TDFA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.1.8
BUILDLINK_ABI_DEPENDS.hs-regex-tdfa+=	hs-regex-tdfa>=1.1.8
BUILDLINK_PKGSRCDIR.hs-regex-tdfa?=	../../wip/hs-regex-tdfa

.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../textproc/hs-parsec/buildlink3.mk"
.include "../../textproc/hs-regex-base/buildlink3.mk"
.endif	# HS_REGEX_TDFA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-regex-tdfa
