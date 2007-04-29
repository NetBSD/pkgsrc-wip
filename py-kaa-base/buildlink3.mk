# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/04/29 16:10:42 dhowland Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PY_KAA_BASE_BUILDLINK3_MK:=	${PY_KAA_BASE_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	py-kaa-base
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npy-kaa-base}
BUILDLINK_PACKAGES+=	py-kaa-base
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}py-kaa-base

.if ${PY_KAA_BASE_BUILDLINK3_MK} == "+"
.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-kaa-base+=	${PYPKGPREFIX}-kaa-base>=0.1.3
BUILDLINK_PKGSRCDIR.py-kaa-base?=	../../wip/py-kaa-base
.endif	# PY_KAA_BASE_BUILDLINK3_MK

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
