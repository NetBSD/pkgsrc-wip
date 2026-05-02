# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xeus

.if !defined(XEUS_BUILDLINK3_MK)
XEUS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xeus+=	xeus>=6.0.2
BUILDLINK_PKGSRCDIR.xeus?=	../../wip/xeus

.include "../../devel/libuuid/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"

.endif	# XEUS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xeus
