# $NetBSD: buildlink3.mk,v 1.2 2008/07/23 15:46:25 hoka_adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WEBKIT_BUILDLINK3_MK:=	${WEBKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	webkit-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nwebkit-gtk}
BUILDLINK_PACKAGES+=	webkit-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}webkit-gtk

.if ${WEBKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=r35249
BUILDLINK_PKGSRCDIR.webkit-gtk?=	../../wip/webkit-gtk
.endif	# WEBKIT_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
