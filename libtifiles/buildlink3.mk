# $NetBSD: buildlink3.mk,v 1.1 2004/03/28 07:59:34 bjan2 Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libtifiles?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTIFILES_BUILDLINK3_MK:=	${LIBTIFILES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libtifiles
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibtifiles}
BUILDLINK_PACKAGES+=	libtifiles

.if !empty(LIBTIFILES_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libtifiles+=	libtifiles>=0.5.6
BUILDLINK_PKGSRCDIR.libtifiles?=	../../wip/libtifiles
.endif	# LIBTIFILES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
