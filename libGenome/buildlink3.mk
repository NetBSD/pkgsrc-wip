# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/19 21:49:17 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libGenome?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBGENOME_BUILDLINK3_MK:=	${LIBGENOME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libGenome
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibGenome}
BUILDLINK_PACKAGES+=	libGenome

.if !empty(LIBGENOME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libGenome+=	libGenome>=0.5.2
BUILDLINK_PKGSRCDIR.libGenome?=	../../wip/libGenome
.endif	# LIBGENOME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
