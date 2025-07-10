# $NetBSD: $

BUILDLINK_TREE+=	py-pyside6

.if !defined(PY_PYSIDE6_BUILDLINK3_MK)
PY_PYSIDE6_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pyside6+=	${PYPKGPREFIX}-pyside6>=6.0.0
BUILDLINK_ABI_DEPENDS.py-pyside6+=	${PYPKGPREFIX}-pyside6>=6.0.0
BUILDLINK_FILES.py-pyside6+=		${PYSITELIB}/PySide6/*
BUILDLINK_FILES.py-pyside6+=		${PYSITELIB}/shiboken6/*
BUILDLINK_FILES.py-pyside6+=		share/PySide6/glue/*
BUILDLINK_PKGSRCDIR.py-pyside6?=	../../wip/py-pyside6

.endif # PY_PYSIDE6_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyside6
