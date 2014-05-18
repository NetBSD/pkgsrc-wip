# $NetBSD: buildlink3.mk,v 1.7 2014/05/18 21:33:29 szptvlfn Exp $

BUILDLINK_TREE+=	hs-shake

.if !defined(HS_SHAKE_BUILDLINK3_MK)
HS_SHAKE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-shake+=	hs-shake>=0.11.4
BUILDLINK_PKGSRCDIR.hs-shake?=	../../wip/hs-shake

.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../wip/hs-random/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-utf8-string/buildlink3.mk"
.endif	# HS_SHAKE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-shake
