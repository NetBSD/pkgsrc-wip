# $NetBSD: buildlink3.mk,v 1.1 2013/11/15 12:14:47 rhialto Exp $

BUILDLINK_TREE+=	py-pyside

.if !defined(PY_PYSIDE_BUILDLINK3_MK)
PY_PYSIDE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pyside+=	${PYPKGPREFIX}-pyside>=1.2.4
BUILDLINK_ABI_DEPENDS.py-pyside+=	${PYPKGPREFIX}-pyside>=1.2.4
BUILDLINK_PKGSRCDIR.py-pyside?=		../../wip/py-pyside
.endif # PY_PYSIDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyside
