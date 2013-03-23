# $NetBSD: buildlink3.mk,v 1.5 2013/03/23 14:58:26 outpaddling Exp $

BUILDLINK_TREE+=	py-ufl

.if !defined(PY_UFL_BUILDLINK3_MK)
PY_UFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-ufl+=	${PYPKGPREFIX}-ufl>=1.0.0
BUILDLINK_PKGSRCDIR.py-ufl?=	../../wip/py-ufl
.endif	# PY_UFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-ufl
