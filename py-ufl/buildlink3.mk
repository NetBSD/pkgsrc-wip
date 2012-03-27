# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/27 15:49:51 outpaddling Exp $

BUILDLINK_TREE+=	py26-ufl

.if !defined(PY26_UFL_BUILDLINK3_MK)
PY26_UFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-ufl+=	py26-ufl>=1.0.0
BUILDLINK_PKGSRCDIR.py26-ufl?=	../../jb-wip/py-ufl
.endif	# PY26_UFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-ufl
