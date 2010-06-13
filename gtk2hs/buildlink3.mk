# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:47:06 thomasklausner Exp $

BUILDLINK_TREE+=	gtk2hs

.if !defined(GTK2HS_BUILDLINK3_MK)
GTK2HS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.gtk2hs?=	build
BUILDLINK_API_DEPENDS.gtk2hs+=	gtk2hs>=0.9.13
BUILDLINK_ABI_DEPENDS.gtk2hs?=	gtk2hs>=0.9.13nb2
BUILDLINK_PKGSRCDIR.gtk2hs?=	../../wip/gtk2hs

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTK2HS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk2hs
