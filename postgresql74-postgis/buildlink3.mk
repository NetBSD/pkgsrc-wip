# $NetBSD: buildlink3.mk,v 1.2 2005/03/31 20:20:42 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.postgresql74-postgis-1.0.0?=	build

BUILDLINK_DEPTH:=				${BUILDLINK_DEPTH}+
POSTGRESQL74_POSTGIS_1.0.0_BUILDLINK3_MK:=	${POSTGRESQL74_POSTGIS_1.0.0_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgresql74-postgis-1.0.0
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgresql74-postgis-1.0.0}
BUILDLINK_PACKAGES+=	postgresql74-postgis-1.0.0

.if !empty(POSTGRESQL74_POSTGIS_1.0.0_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgresql74-postgis-1.0.0+=	postgresql74-postgis-1.0.0>=rc2
BUILDLINK_PKGSRCDIR.postgresql74-postgis-1.0.0?=	../../wip/postgresql74-postgis
.endif	# POSTGRESQL74_POSTGIS_1.0.0_BUILDLINK3_MK

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../wip/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
