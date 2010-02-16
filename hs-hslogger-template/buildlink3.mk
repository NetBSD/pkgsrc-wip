# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/16 10:19:39 phonohawk Exp $

BUILDLINK_TREE+=	hs-hslogger-template

.if !defined(HS_HSLOGGER_TEMPLATE_BUILDLINK3_MK)
HS_HSLOGGER_TEMPLATE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslogger-template+=	hs-hslogger-template>=1.0.0
BUILDLINK_PKGSRCDIR.hs-hslogger-template?=	../../wip/hs-hslogger-template

.include "../../wip/hs-hslogger/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.endif	# HS_HSLOGGER_TEMPLATE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslogger-template
