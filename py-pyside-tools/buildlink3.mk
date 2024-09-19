# $NetBSD: buildlink3.mk,v 1.1 2013/11/15 12:14:47 rhialto Exp $

BUILDLINK_TREE+=	py-pyside-tools

.if !defined(PY_PYSIDE_TOOLS_BUILDLINK3_MK)
PY_PYSIDE_TOOLS_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pyside-tools+=	${PYPKGPREFIX}-pyside-tools>=0.2.15
BUILDLINK_ABI_DEPENDS.py-pyside-tools+=	${PYPKGPREFIX}-pyside-tools>=0.2.15
BUILDLINK_PKGSRCDIR.py-pyside-tools?=	../../wip/py-pyside-tools
.endif # PY_PYSIDE_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyside-tools
