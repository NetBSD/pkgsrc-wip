# $NetBSD: buildlink2.mk,v 1.4 2003/06/15 11:45:26 marc Exp $
#

.if !defined(GTK_SHARP_BUILDLINK2_MK)
GTK_SHARP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gtk-sharp
BUILDLINK_DEPENDS.gtk-sharp?=		gtk-sharp>=0.10
BUILDLINK_PKGSRCDIR.gtk-sharp?=		../../wip/gtk-sharp

EVAL_PREFIX+=	BUILDLINK_PREFIX.gtk-sharp=gtk-sharp
BUILDLINK_PREFIX.gtk-sharp_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gtk-sharp+=	lib/art-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/atk-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gconf-sharp-peditors.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gconf-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gda-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gdk-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/glade-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/glib-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gnome-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gnomedb-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/gtk-sharp.dll
BUILDLINK_FILES.gtk-sharp+=	lib/libgtksharpglue.*
BUILDLINK_FILES.gtk-sharp+=	lib/pango-sharp.dll

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../graphics/librsvg2/buildlink2.mk"
.include "../../lang/mono/buildlink2.mk"
.include "../../www/libgtkhtml/buildlink2.mk"

BUILDLINK_TARGETS+=	gtk-sharp-buildlink

gtk-sharp-buildlink: _BUILDLINK_USE

.endif	# GTK_SHARP_BUILDLINK2_MK
