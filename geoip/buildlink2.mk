# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/24 23:56:47 xtraeme Exp $
#
# This Makefile fragment is included by packages that use geoip.
#
# This file was created automatically using createbuildlink 2.5.
#

.if !defined(GEOIP_BUILDLINK2_MK)
GEOIP_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			geoip
BUILDLINK_DEPENDS.geoip?=		geoip>=1.1.9
BUILDLINK_PKGSRCDIR.geoip?=		../../wip/geoip

EVAL_PREFIX+=	BUILDLINK_PREFIX.geoip=geoip
BUILDLINK_PREFIX.geoip_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.geoip+=	include/GeoIP.h
BUILDLINK_FILES.geoip+=	include/GeoIPBitReader.h
BUILDLINK_FILES.geoip+=	include/GeoIPCity.h
BUILDLINK_FILES.geoip+=	include/GeoIPUpdate.h
BUILDLINK_FILES.geoip+=	lib/libGeoIP.*
BUILDLINK_FILES.geoip+=	lib/libGeoIPBitReader.*
BUILDLINK_FILES.geoip+=	lib/libGeoIPUpdate.*

BUILDLINK_TARGETS+=	geoip-buildlink

geoip-buildlink: _BUILDLINK_USE

.endif	# GEOIP_BUILDLINK2_MK
