# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/19 21:50:59 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgrass5?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGRASS5_BUILDLINK3_MK:=	${LIBGRASS5_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgrass5
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgrass5}
BUILDLINK_PACKAGES+=	libgrass5

.if !empty(LIBGRASS5_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgrass5+=	libgrass5>=1.0.0
BUILDLINK_PKGSRCDIR.libgrass5?=	../../wip/libgrass5
.endif	# LIBGRASS5_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
