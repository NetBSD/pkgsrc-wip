# $NetBSD: buildlink2.mk,v 1.1.1.1 2005/03/18 23:07:31 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.postgis?=	build

.if !defined(POSTGIS_BUILDLINK2_MK)
POSTGIS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		postgis
BUILDLINK_DEPENDS.postgis?=	postgis>=0.7.5
BUILDLINK_PKGSRCDIR.postgis?=	../../wip/postgis

EVAL_PREFIX+=	BUILDLINK_PREFIX.postgis=postgis
BUILDLINK_PREFIX.postgis_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.postgis+=	lib/postgresql/libpostgis.*

.include "../../databases/postgresql-lib/buildlink2.mk"

BUILDLINK_TARGETS+=	postgis-buildlink

postgis-buildlink: _BUILDLINK_USE

.endif	# POSTGIS_BUILDLINK2_MK
