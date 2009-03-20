# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:42 jsonn Exp $

BUILDLINK_TREE+=	gtkhotkey

.if !defined(GTKHOTKEY_BUILDLINK3_MK)
GTKHOTKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkhotkey+=	gtkhotkey>=0.2.0
BUILDLINK_PKGSRCDIR.gtkhotkey?=	../../wip/gtkhotkey

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKHOTKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkhotkey
