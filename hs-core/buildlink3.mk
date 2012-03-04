# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/04 08:59:45 phonohawk Exp $

BUILDLINK_TREE+=	hs-core

.if !defined(HS_CORE_BUILDLINK3_MK)
HS_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-core+=	hs-core>=0.5
BUILDLINK_PKGSRCDIR.hs-core?=	../../wip/hs-core

.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-core
