# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/15 16:00:03 poppnk Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.7.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libvg?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBVG_BUILDLINK3_MK:=	${LIBVG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libvg
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibvg}
BUILDLINK_PACKAGES+=	libvg

.if !empty(LIBVG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libvg+=	libvg>=0.2.0
BUILDLINK_PKGSRCDIR.libvg?=	../../wip/libvg
.endif	# LIBVG_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
