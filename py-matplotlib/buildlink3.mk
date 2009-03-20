# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:52 jsonn Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	pymatplotlib

.if !defined(PY_MATPLOTLIB_BUILDLINK3_MK)
PY_MATPLOTLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
BUILDLINK_PKGSRCDIR.pymatplotlib?=	../../wip/py-matplotlib
.endif # PY_MATPLOTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymatplotlib
