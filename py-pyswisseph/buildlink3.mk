# $NetBSD: buildlink3.mk,v 1.1 2013/01/07 03:28:49 othyro Exp $

BUILDLINK_TREE+=	py-pyswisseph

.if !defined(PY_PYSWISSEPH_BUILDLINK3_MK)
PY_PYSWISSEPH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pyswisseph+=	${PYPKGPREFIX}-pyswisseph>=1.77.00-0
BUILDLINK_PKGSRCDIR.py-pyswisseph?=	../../wip/py-pyswisseph
.endif	# PY_PYSWISSEPH_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyswisseph
