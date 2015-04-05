# $NetBSD: buildlink3.mk,v 1.1 2015/04/05 19:46:56 krytarowski Exp $

BUILDLINK_TREE+=	keybinder

.if !defined(KEYBINDER_BUILDLINK3_MK)
KEYBINDER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.keybinder+=	keybinder>=0.3.0
BUILDLINK_PKGSRCDIR.keybinder?=	../../wip/keybinder

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# KEYBINDER_BUILDLINK3_MK

BUILDLINK_TREE+=	-keybinder
