# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:11 szptvlfn Exp $

BUILDLINK_TREE+=	hs-core

.if !defined(HS_CORE_BUILDLINK3_MK)
HS_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-core+=	hs-core>=0.5
BUILDLINK_ABI_DEPENDS.hs-core+=	hs-core>=0.5
BUILDLINK_PKGSRCDIR.hs-core?=	../../wip/hs-core

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-core
