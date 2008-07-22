# $NetBSD: buildlink3.mk,v 1.1 2008/07/22 18:43:50 hoka_adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
WEBKIT_BUILDLINK3_MK:=	${WEBKIT_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	WebKit
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NWebKit}
BUILDLINK_PACKAGES+=	WebKit
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}WebKit

.if ${WEBKIT_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.WebKit+=	WebKit>=r35249
BUILDLINK_PKGSRCDIR.WebKit?=	../../wip/webkit-gtk
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
