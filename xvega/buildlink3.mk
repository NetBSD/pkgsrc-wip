# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xvega

.if !defined(XVEGA_BUILDLINK3_MK)
XVEGA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xvega+=	xvega>=0.1.3
BUILDLINK_PKGSRCDIR.xvega?=	../../wip/xvega

.include "../../wip/xproperty/buildlink3.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"

.endif	# XVEGA_BUILDLINK3_MK

BUILDLINK_TREE+=	-xvega
