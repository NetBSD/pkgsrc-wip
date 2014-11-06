# $NetBSD: buildlink3.mk,v 1.5 2014/11/06 13:02:51 szptvlfn Exp $

BUILDLINK_TREE+=	hs-reflection

.if !defined(HS_REFLECTION_BUILDLINK3_MK)
HS_REFLECTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-reflection+=	hs-reflection>=1.5.1
BUILDLINK_ABI_DEPENDS.hs-reflection+=	hs-reflection>=1.5.1
BUILDLINK_PKGSRCDIR.hs-reflection?=	../../wip/hs-reflection

.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_REFLECTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-reflection
