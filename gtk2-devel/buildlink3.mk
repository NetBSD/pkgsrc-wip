# $NetBSD: buildlink3.mk,v 1.1 2004/03/17 11:48:56 mpasternak Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.2.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTK+_BUILDLINK3_MK:=	${GTK+_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk+
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk+}
BUILDLINK_PACKAGES+=	gtk+

.if !empty(GTK+_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtk++=	gtk+>=2.4.0
BUILDLINK_PKGSRCDIR.gtk+?=	../../wip/gtk2-devel

.include "../../wip/pango-devel/buildlink3.mk"
.include "../../wip/atk-devel/buildlink3.mk"
.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif	# GTK+_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
