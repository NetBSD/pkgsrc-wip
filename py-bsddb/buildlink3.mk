# $NetBSD: buildlink3.mk,v 1.1 2004/05/10 11:26:45 marc Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PYBSDDB_BUILDLINK3_MK:=	${PYBSDDB_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pybsddb
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npybsddb}
BUILDLINK_PACKAGES+=	pybsddb

.if !empty(PYBSDDB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.pybsddb+=	${PYPKGPREFIX}-bsddb>=0
BUILDLINK_PKGSRCDIR.pybsddb?=	../../wip/py-bsddb
.endif	# PYBSDDB_BUILDLINK3_MK

.include "../../databases/db4/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
