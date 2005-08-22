# $NetBSD: buildlink3.mk,v 1.4 2005/08/22 20:22:59 mchittur Exp $

BUILDLINK_DEPMETHOD.ncbi-lib?=	build

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
NCBI_LIB_BUILDLINK3_MK:=	${NCBI_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ncbi-lib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nncbi-lib}
BUILDLINK_PACKAGES+=	ncbi-lib

.if !empty(NCBI_LIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ncbi-lib+=	ncbi-lib>=20050605
BUILDLINK_PKGSRCDIR.ncbi-lib?=	../../wip/ncbi-lib
.endif	# NCBI_LIB_BUILDLINK3_MK

.include "../../mk/x11.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
