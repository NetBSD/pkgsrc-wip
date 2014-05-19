# $NetBSD: buildlink3.mk,v 1.2 2014/05/19 21:28:47 szptvlfn Exp $

BUILDLINK_TREE+=	hs-core

.if !defined(HS_CORE_BUILDLINK3_MK)
HS_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-core+=	hs-core>=0.5
BUILDLINK_PKGSRCDIR.hs-core?=	../../wip/hs-core

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-core
