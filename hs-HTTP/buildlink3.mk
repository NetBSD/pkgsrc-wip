# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	hs-HTTP

.if !defined(HS_HTTP_BUILDLINK3_MK)
HS_HTTP_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-HTTP?=	build
BUILDLINK_API_DEPENDS.hs-HTTP+=	hs-HTTP>=4000.0.1
BUILDLINK_PKGSRCDIR.hs-HTTP?=	../../wip/hs-HTTP

.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/parsec/buildlink3.mk"
.endif # HS_HTTP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HTTP
