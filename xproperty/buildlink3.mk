# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xproperty

.if !defined(XPROPERTY_BUILDLINK3_MK)
XPROPERTY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xproperty+=	xproperty>=0.12.0
BUILDLINK_PKGSRCDIR.xproperty?=		../../wip/xproperty

.include "../../textproc/nlohmann-json/buildlink3.mk"

.endif	# XPROPERTY_BUILDLINK3_MK

BUILDLINK_TREE+=	-xproperty
