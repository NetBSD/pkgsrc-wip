# $NetBSD: buildlink3.mk,v 1.2 2012/03/11 08:17:52 phonohawk Exp $

BUILDLINK_TREE+=	hs-gtk

.if !defined(HS_GTK_BUILDLINK3_MK)
HS_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gtk+=	hs-gtk>=0.12.3
BUILDLINK_PKGSRCDIR.hs-gtk?=	../../wip/hs-gtk

.include "../../wip/hs-cairo/buildlink3.mk"
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../wip/hs-mtl/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# HS_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gtk
