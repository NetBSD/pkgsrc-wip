# $NetBSD: buildlink3.mk,v 1.3 2005/03/30 16:45:04 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.geos?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GEOS_BUILDLINK3_MK:=	${GEOS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	geos
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngeos}
BUILDLINK_PACKAGES+=	geos

.if !empty(GEOS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.geos+=	geos>=2.0.0
BUILDLINK_PKGSRCDIR.geos?=	../../wip/geos
.endif	# GEOS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
