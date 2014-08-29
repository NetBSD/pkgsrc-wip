# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=1.4
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=1.4
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../wip/hs-reflection

.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
