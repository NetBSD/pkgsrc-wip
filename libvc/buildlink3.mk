# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/08/05 20:49:19 poppnk Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.8.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libvc?=	build

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBVC_BUILDLINK3_MK:=	${LIBVC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libvc
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibvc}
BUILDLINK_PACKAGES+=	libvc

.if !empty(LIBVC_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libvc+=	libvc>=003
BUILDLINK_PKGSRCDIR.libvc?=	../../wip/libvc
.endif	# LIBVC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
