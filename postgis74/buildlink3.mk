# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/03/18 23:08:40 daprice Exp $
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

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
POSTGIS_BUILDLINK3_MK:=	${POSTGIS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	postgis
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npostgis}
BUILDLINK_PACKAGES+=	postgis

.if !empty(POSTGIS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.postgis+=	postgis>=0.8.2
BUILDLINK_PKGSRCDIR.postgis?=	../../wip/postgis74
.endif	# POSTGIS_BUILDLINK3_MK

.include "../../wip/geos/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../databases/postgresql74-lib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
