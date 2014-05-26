# $NetBSD: buildlink3.mk,v 1.4 2014/05/26 22:08:04 szptvlfn Exp $

BUILDLINK_TREE+=	hs-blaze-builder-conduit

.if !defined(HS_BLAZE_BUILDER_CONDUIT_BUILDLINK3_MK)
HS_BLAZE_BUILDER_CONDUIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-blaze-builder-conduit+=	hs-blaze-builder-conduit>=1.0.0
BUILDLINK_PKGSRCDIR.hs-blaze-builder-conduit?=	../../wip/hs-blaze-builder-conduit

.include "../../devel/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../devel/hs-text/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_BLAZE_BUILDER_CONDUIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-blaze-builder-conduit
