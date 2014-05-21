# $NetBSD: buildlink3.mk,v 1.6 2014/05/21 21:04:43 szptvlfn Exp $

BUILDLINK_TREE+=	hs-aeson

.if !defined(HS_AESON_BUILDLINK3_MK)
HS_AESON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-aeson+=	hs-aeson>=0.7.0
BUILDLINK_PKGSRCDIR.hs-aeson?=	../../wip/hs-aeson

.include "../../wip/hs-attoparsec/buildlink3.mk"
.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../devel/hs-dlist/buildlink3.mk"
.include "../../wip/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-scientific/buildlink3.mk"
.include "../../devel/hs-syb/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../wip/hs-unordered-containers/buildlink3.mk"
.include "../../wip/hs-vector/buildlink3.mk"
.endif	# HS_AESON_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-aeson
