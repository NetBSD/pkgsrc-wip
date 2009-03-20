# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	bakery

.if !defined(BAKERY_BUILDLINK3_MK)
BAKERY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bakery+=	bakery>=2.6.3
BUILDLINK_PKGSRCDIR.bakery?=	../../wip/bakery

.include "../../x11/gtkmm/buildlink3.mk"
.endif # BAKERY_BUILDLINK3_MK

BUILDLINK_TREE+=	-bakery
