# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:47:07 thomasklausner Exp $

BUILDLINK_TREE+=	gtkhotkey

.if !defined(GTKHOTKEY_BUILDLINK3_MK)
GTKHOTKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkhotkey+=	gtkhotkey>=0.2.0
BUILDLINK_ABI_DEPENDS.gtkhotkey?=	gtkhotkey>=0.2.1nb1
BUILDLINK_PKGSRCDIR.gtkhotkey?=		../../wip/gtkhotkey

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKHOTKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkhotkey
