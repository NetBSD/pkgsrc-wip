# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/29 18:04:07 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.shapelib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SHAPELIB_BUILDLINK3_MK:=	${SHAPELIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	shapelib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nshapelib}
BUILDLINK_PACKAGES+=	shapelib

.if !empty(SHAPELIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.shapelib+=	shapelib>=1.2.10
BUILDLINK_PKGSRCDIR.shapelib?=	../../wip/shapelib
.endif	# SHAPELIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
