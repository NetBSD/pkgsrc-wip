# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/28 07:55:51 bjan2 Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libticalcs?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBTICALCS_BUILDLINK3_MK:=	${LIBTICALCS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libticalcs
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibticalcs}
BUILDLINK_PACKAGES+=	libticalcs

.if !empty(LIBTICALCS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libticalcs+=	libticalcs>=4.4.9
BUILDLINK_PKGSRCDIR.libticalcs?=	../../wip/libticalcs
.endif	# LIBTICALCS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
