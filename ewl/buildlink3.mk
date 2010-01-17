# $NetBSD: buildlink3.mk,v 1.3 2010/01/17 12:03:25 thomasklausner Exp $

BUILDLINK_TREE+=	ewl

.if !defined(EWL_BUILDLINK3_MK)
EWL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ewl+=	ewl>=0.5.2.042
BUILDLINK_ABI_DEPENDS.ewl?=	ewl>=0.5.2.042nb2
BUILDLINK_PKGSRCDIR.ewl?=	../../wip/ewl

.include "../../wip/efreet/buildlink3.mk"
.include "../../wip/edje/buildlink3.mk"
.include "../../wip/epsilon/buildlink3.mk"
.endif # EWL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ewl
