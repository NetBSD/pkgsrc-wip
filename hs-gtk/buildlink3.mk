# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:14 szptvlfn Exp $

BUILDLINK_TREE+=	hs-gtk

.if !defined(HS_GTK_BUILDLINK3_MK)
HS_GTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gtk+=	hs-gtk>=0.12.3
BUILDLINK_ABI_DEPENDS.hs-gtk+=	hs-gtk>=0.12.3
BUILDLINK_PKGSRCDIR.hs-gtk?=	../../wip/hs-gtk

.include "../../wip/hs-cairo/buildlink3.mk"
.include "../../wip/hs-glib/buildlink3.mk"
.include "../../devel/hs-mtl/buildlink3.mk"
.include "../../wip/hs-pango/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# HS_GTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gtk
