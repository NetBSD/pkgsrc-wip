# $NetBSD: buildlink3.mk,v 1.2 2004/03/17 20:02:42 mpasternak Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GTK2_BUILDLINK3_MK:=	${GTK2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gtk2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngtk2+}
BUILDLINK_PACKAGES+=	gtk2

.if !empty(GTK2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gtk2+=	gtk2+>=2.4.0
BUILDLINK_PKGSRCDIR.gtk2?=	../../wip/gtk2-devel

.include "../../wip/pango-devel/buildlink3.mk"
.include "../../wip/atk-devel/buildlink3.mk"
.include "../../wip/glib2-devel/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"

.endif	# GTK2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
