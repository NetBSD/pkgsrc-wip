# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:46:57 thomasklausner Exp $

BUILDLINK_TREE+=	bakery

.if !defined(BAKERY_BUILDLINK3_MK)
BAKERY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bakery+=	bakery>=2.6.3
BUILDLINK_ABI_DEPENDS.bakery?=	bakery>=2.6.3nb1
BUILDLINK_PKGSRCDIR.bakery?=	../../wip/bakery

.include "../../x11/gtkmm/buildlink3.mk"
.endif # BAKERY_BUILDLINK3_MK

BUILDLINK_TREE+=	-bakery
