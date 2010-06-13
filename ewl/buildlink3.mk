# $NetBSD: buildlink3.mk,v 1.5 2010/06/13 22:47:03 thomasklausner Exp $

BUILDLINK_TREE+=	ewl

.if !defined(EWL_BUILDLINK3_MK)
EWL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ewl+=	ewl>=0.5.2.042
BUILDLINK_ABI_DEPENDS.ewl?=	ewl>=0.5.2.042nb4
BUILDLINK_PKGSRCDIR.ewl?=	../../wip/ewl

.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.endif # EWL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ewl
