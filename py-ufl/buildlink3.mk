# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 17:48:00 outpaddling Exp $

BUILDLINK_TREE+=	py26-ufl

.if !defined(PY26_UFL_BUILDLINK3_MK)
PY26_UFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-ufl+=	py26-ufl>=1.0.0
BUILDLINK_PKGSRCDIR.py26-ufl?=	../../wip/py-ufl
.endif	# PY26_UFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-ufl
