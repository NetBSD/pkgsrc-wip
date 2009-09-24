# $NetBSD: buildlink3.mk,v 1.5 2009/09/24 07:22:12 phonohawk Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.0.8
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../wip/hs-HTTP

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
