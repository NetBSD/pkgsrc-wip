# $NetBSD: buildlink3.mk,v 1.2 2014/01/29 22:28:56 szptvlfn Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=1.4
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../wip/hs-reflection

.include "../../wip/hs-tagged/buildlink3.mk"
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
