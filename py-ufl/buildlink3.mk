# $NetBSD: buildlink3.mk,v 1.4 2012/05/12 14:33:39 outpaddling Exp $

BUILDLINK_TREE+=	ufl

.if !defined(PY_UFL_BUILDLINK3_MK)
PY_UFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ufl+=	${PYPKGPREFIX}-ufl>=1.0.0
BUILDLINK_PKGSRCDIR.ufl?=	../../wip/py-ufl
.endif	# PY_UFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ufl
