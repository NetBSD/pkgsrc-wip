# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xcanvas

.if !defined(XCANVAS_BUILDLINK3_MK)
XCANVAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xcanvas+=	xcanvas>=0.7.0
BUILDLINK_PKGSRCDIR.xcanvas?=	../../wip/xcanvas

.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xwidgets/buildlink3.mk"
.include "../../textproc/nlohmann-json/buildlink3.mk"

.endif	# XCANVAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xcanvas
