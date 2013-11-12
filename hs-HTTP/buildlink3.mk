# $NetBSD: buildlink3.mk,v 1.9 2013/11/12 09:57:37 szptvlfn Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.2.9
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../wip/hs-HTTP

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-parsec/buildlink3.mk"
.endif	# HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
