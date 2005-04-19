# $NetBSD: buildlink3.mk,v 1.5 2005/04/19 22:32:27 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.gdal-lib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GDAL_LIB_BUILDLINK3_MK:=	${GDAL_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gdal-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngdal-lib}
BUILDLINK_PACKAGES+=	gdal-lib

.if !empty(GDAL_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gdal-lib+=	gdal-lib>=1.2.6
BUILDLINK_PKGSRCDIR.gdal-lib?=	../../wip/gdal-lib
.endif	# GDAL_LIB_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../misc/proj/buildlink3.mk"
#.include "../../wip/geos/buildlink3.mk"
#.include "../../textproc/xerces-c/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
