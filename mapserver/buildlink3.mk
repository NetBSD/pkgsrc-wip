# $NetBSD: buildlink3.mk,v 1.2 2005/03/18 20:34:30 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.mapserver?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
MAPSERVER_BUILDLINK3_MK:=	${MAPSERVER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mapserver
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmapserver}
BUILDLINK_PACKAGES+=	mapserver

.if !empty(MAPSERVER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mapserver+=	mapserver>=4.4.1
BUILDLINK_PKGSRCDIR.mapserver?=	../../wip/mapserver-4.4.1
.endif	# MAPSERVER_BUILDLINK3_MK

.include "../../www/curl/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../print/pdflib/buildlink3.mk"
.include "../../www/php4/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../wip/gdal-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/geos2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
