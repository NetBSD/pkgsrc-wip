# $NetBSD: buildlink3.mk,v 1.55 2024/04/07 07:35:20 wiz Exp $

BUILDLINK_TREE+=	gtksourceview2

.if !defined(GTKSOURCEVIEW2_BUILDLINK3_MK)
GTKSOURCEVIEW2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourceview2+=	gtksourceview2>=2.0.2<3
BUILDLINK_ABI_DEPENDS.gtksourceview2+=	gtksourceview2>=2.10.5nb55
BUILDLINK_PKGSRCDIR.gtksourceview2?=	../../wip/gtksourceview2

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # GTKSOURCEVIEW2_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourceview2
