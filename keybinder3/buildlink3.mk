# $NetBSD: buildlink3.mk,v 1.2 2015/04/06 10:40:32 krytarowski Exp $

BUILDLINK_TREE+=	keybinder3

.if !defined(KEYBINDER3_BUILDLINK3_MK)
KEYBINDER3_BUILDLINK3_MK:=

BUILDLINK3_API_DEPENDS.keybinder+=	keybinder>=0.3.0
BUILDLINK3_PKGSRCDIR.keybinder?=	../../wip/keybinder

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# KEYBINDER3_BUILDLINK3_MK

BUILDLINK_TREE+=	-keybinder3
