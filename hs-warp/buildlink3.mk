# $NetBSD: buildlink3.mk,v 1.1 2013/11/27 00:09:39 szptvlfn Exp $

BUILDLINK_TREE+=	hs-warp

.if !defined(HS_WARP_BUILDLINK3_MK)
HS_WARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-warp+=	hs-warp>=1.3.10
BUILDLINK_PKGSRCDIR.hs-warp?=	../../wip/hs-warp

.include "../../wip/hs-blaze-builder/buildlink3.mk"
.include "../../wip/hs-blaze-builder-conduit/buildlink3.mk"
.include "../../wip/hs-case-insensitive/buildlink3.mk"
.include "../../wip/hs-conduit/buildlink3.mk"
.include "../../wip/hs-http-attoparsec/buildlink3.mk"
.include "../../wip/hs-http-types/buildlink3.mk"
.include "../../wip/hs-lifted-base/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-network-conduit/buildlink3.mk"
.include "../../wip/hs-simple-sendfile/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-unix-compat/buildlink3.mk"
.include "../../wip/hs-void/buildlink3.mk"
.include "../../wip/hs-wai/buildlink3.mk"
.endif	# HS_WARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-warp
