# $NetBSD: buildlink3.mk,v 1.8 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-profunctors

.if !defined(HS_PROFUNCTORS_BUILDLINK3_MK)
HS_PROFUNCTORS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-profunctors+=	hs-profunctors>=4.2.0
BUILDLINK_ABI_DEPENDS.hs-profunctors+=	hs-profunctors>=4.2.0.1
BUILDLINK_PKGSRCDIR.hs-profunctors?=	../../wip/hs-profunctors

.include "../../math/hs-comonad/buildlink3.mk"
.include "../../math/hs-distributive/buildlink3.mk"
.include "../../wip/hs-semigroupoids/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_PROFUNCTORS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-profunctors
