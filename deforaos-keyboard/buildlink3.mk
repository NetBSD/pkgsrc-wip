# $NetBSD: buildlink3.mk,v 1.2 2014/06/26 12:06:06 khorben Exp $

BUILDLINK_TREE+=	deforaos-keyboard

.if !defined(DEFORAOS_KEYBOARD_BUILDLINK3_MK)
DEFORAOS_KEYBOARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.deforaos-keyboard+=	deforaos-keyboard>=0.0.2
BUILDLINK_PKGSRCDIR.deforaos-keyboard?=		../../wip/deforaos-keyboard

.include "../../x11/gtk3/buildlink3.mk"
.endif	# DEFORAOS_KEYBOARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-deforaos-keyboard
