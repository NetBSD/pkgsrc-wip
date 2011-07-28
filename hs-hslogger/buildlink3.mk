# $NetBSD: buildlink3.mk,v 1.3 2011/07/28 12:55:38 phonohawk Exp $

BUILDLINK_TREE+=	hs-hslogger

.if !defined(HS_HSLOGGER_BUILDLINK3_MK)
HS_HSLOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslogger+=	hs-hslogger>=1.1.4
BUILDLINK_PKGSRCDIR.hs-hslogger?=	../../wip/hs-hslogger

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.endif	# HS_HSLOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslogger
