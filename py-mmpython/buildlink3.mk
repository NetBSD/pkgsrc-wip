# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:21 jeremy-c-reed Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_MMPYTHON_BUILDLINK3_MK:=	${PY_MMPYTHON_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pymmpython
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npymmpython}
BUILDLINK_PACKAGES+=	pymmpython

.if !empty(PY_MMPYTHON_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.pymmpython+=		${PYPKGPREFIX}-mmpython>=0.3
BUILDLINK_PKGSRCDIR.pymmpython?=	../../wip/py-mmpython
.endif	# PY_MMPYTHON_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
