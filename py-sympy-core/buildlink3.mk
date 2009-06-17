# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/06/17 23:15:08 jihbed Exp $

BUILDLINK_TREE+=	py-sympycore

.if !defined(PY25_SYMPYCORE_BUILDLINK3_MK)
PY_SYMPYCORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-sympycore+=	py-sympycore>=0.1
BUILDLINK_PKGSRCDIR.py-sympycore?=	../../wip/py-sympy-core
.endif	# PY_SYMPYCORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sympycore
