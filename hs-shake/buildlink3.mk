# $NetBSD: buildlink3.mk,v 1.11 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-shake

.if !defined(HS_SHAKE_BUILDLINK3_MK)
HS_SHAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-shake+=	hs-shake>=0.11.4
BUILDLINK_ABI_DEPENDS.hs-shake+=	hs-shake>=0.11.4
BUILDLINK_PKGSRCDIR.hs-shake?=		../../wip/hs-shake

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_SHAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-shake
