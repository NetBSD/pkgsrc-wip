# $NetBSD: buildlink3.mk,v 1.5 2014/09/01 13:57:15 makoto Exp $

BUILDLINK_TREE+=	pymatplotlib

.if !defined(PYMATPLOTLIB_BUILDLINK3_MK)
PYMATPLOTLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pymatplotlib+=	${PYPKGPREFIX}-matplotlib>=0.87.2
BUILDLINK_PKGSRCDIR.pymatplotlib?=	../../wip/py-matplotlib
.endif # PYMATPLOTLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pymatplotlib
