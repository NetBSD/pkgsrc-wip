# $NetBSD: buildlink3.mk,v 1.1 2022/12/28 20:18:21 nikita Exp $

BUILDLINK_TREE+=	xwidgets

.if !defined(XWIDGETS_BUILDLINK3_MK)
XWIDGETS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xwidgets+=	xwidgets>=0.30.0
BUILDLINK_PKGSRCDIR.xwidgets?=		../../wip/xwidgets

.include "../../wip/xproperty/buildlink3.mk"
.include "../../wip/xeus/buildlink3.mk"
.include "../../wip/xproperty/buildlink3.mk"

.endif	# XWIDGETS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xwidgets
