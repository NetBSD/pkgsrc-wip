# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/11/29 17:59:55 daprice Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.4.
# XXX After this file as been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink[23].mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.ncbi-lib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NCBI_LIB_BUILDLINK3_MK:=	${NCBI_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ncbi-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nncbi-lib}
BUILDLINK_PACKAGES+=	ncbi-lib

.if !empty(NCBI_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ncbi-lib+=	ncbi-lib>=20040505
BUILDLINK_PKGSRCDIR.ncbi-lib?=	../../wip/ncbi-lib
.endif	# NCBI_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
