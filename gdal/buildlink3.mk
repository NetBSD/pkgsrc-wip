# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/02/25 20:26:56 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gdal?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GDAL_BUILDLINK3_MK:=	${GDAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdal}
BUILDLINK_PACKAGES+=	gdal

.if !empty(GDAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gdal+=	gdal>=1.1.9
BUILDLINK_PKGSRCDIR.gdal?=	../../wip/gdal
.endif	# GDAL_BUILDLINK3_MK

.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../lang/python15/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
