# $NetBSD: buildlink2.mk,v 1.1.1.1 2005/02/25 20:26:56 daprice Exp $
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

.if !defined(GDAL_BUILDLINK2_MK)
GDAL_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		gdal
BUILDLINK_DEPENDS.gdal?=	gdal>=1.1.9
BUILDLINK_PKGSRCDIR.gdal?=	../../wip/gdal

EVAL_PREFIX+=	BUILDLINK_PREFIX.gdal=gdal
BUILDLINK_PREFIX.gdal_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gdal+=	include/cpl_config.h
BUILDLINK_FILES.gdal+=	include/cpl_conv.h
BUILDLINK_FILES.gdal+=	include/cpl_csv.h
BUILDLINK_FILES.gdal+=	include/cpl_error.h
BUILDLINK_FILES.gdal+=	include/cpl_list.h
BUILDLINK_FILES.gdal+=	include/cpl_minixml.h
BUILDLINK_FILES.gdal+=	include/cpl_multiproc.h
BUILDLINK_FILES.gdal+=	include/cpl_port.h
BUILDLINK_FILES.gdal+=	include/cpl_string.h
BUILDLINK_FILES.gdal+=	include/cpl_vsi.h
BUILDLINK_FILES.gdal+=	include/gdal.h
BUILDLINK_FILES.gdal+=	include/gdal_alg.h
BUILDLINK_FILES.gdal+=	include/gdal_frmts.h
BUILDLINK_FILES.gdal+=	include/gdal_priv.h
BUILDLINK_FILES.gdal+=	include/gdalwarper.h
BUILDLINK_FILES.gdal+=	include/gvgcpfit.h
BUILDLINK_FILES.gdal+=	include/iso8211.h
BUILDLINK_FILES.gdal+=	include/sdts_al.h
BUILDLINK_FILES.gdal+=	include/ogr_api.h
BUILDLINK_FILES.gdal+=	include/ogr_core.h
BUILDLINK_FILES.gdal+=	include/ogr_feature.h
BUILDLINK_FILES.gdal+=	include/ogr_featurestyle.h
BUILDLINK_FILES.gdal+=	include/ogr_geometry.h
BUILDLINK_FILES.gdal+=	include/ogr_p.h
BUILDLINK_FILES.gdal+=	include/ogr_spatialref.h
BUILDLINK_FILES.gdal+=	include/ogr_srs_api.h
BUILDLINK_FILES.gdal+=	include/ogrsf_frmts.h
BUILDLINK_FILES.gdal+=	lib/cpl.*
BUILDLINK_FILES.gdal+=	lib/gdal.*
BUILDLINK_FILES.gdal+=	lib/libgdal.1.1.*
BUILDLINK_FILES.gdal+=	lib/libiso8211.*
BUILDLINK_FILES.gdal+=	lib/libsdts_al.*
BUILDLINK_FILES.gdal+=	lib/ogr.*
BUILDLINK_FILES.gdal+=	lib/ogrsf_frmts.*
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/_gdalmodule.*
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/epsg_tr.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/esri2wkt.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gcps2wld.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdal.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdal2xyz.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdal_merge.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdalchksum.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdalconst.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdalimport.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/gdalnumeric.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/ogr.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/osr.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/pct2rgb.py
BUILDLINK_FILES.gdal+=	lib/python1.5/site-packages/rgb2pct.py

.include "../../databases/postgresql74-lib/buildlink2.mk"
.include "../../lang/python15/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../textproc/xerces-c/buildlink2.mk"

BUILDLINK_TARGETS+=	gdal-buildlink

gdal-buildlink: _BUILDLINK_USE

.endif	# GDAL_BUILDLINK2_MK
