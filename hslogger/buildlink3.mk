# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:43 jsonn Exp $

BUILDLINK_TREE+=	hslogger

.if !defined(HSLOGGER_BUILDLINK3_MK)
HSLOGGER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hslogger?=	build
BUILDLINK_API_DEPENDS.hslogger+=	hslogger>=1.0.7
BUILDLINK_PKGSRCDIR.hslogger?=	../../wip/hslogger

.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-network/buildlink3.mk"
.include "../../wip/hs-time/buildlink3.mk"
.endif # HSLOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hslogger
