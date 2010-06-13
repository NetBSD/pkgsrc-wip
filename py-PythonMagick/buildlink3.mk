# $NetBSD: buildlink3.mk,v 1.4 2010/06/13 22:47:14 thomasklausner Exp $

BUILDLINK_TREE+=	py-PythonMagick

.if !defined(PY_PYTHONMAGICK_BUILDLINK3_MK)
PY_PYTHONMAGICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-PythonMagick+=	${PYPKGPREFIX}-PythonMagick>=0.9.1
BUILDLINK_ABI_DEPENDS.py-PythonMagick?=	${PYPKGPREFIX}-PythonMagick>=0.9.1nb3
BUILDLINK_PKGSRCDIR.py-PythonMagick?=	../../wip/py-PythonMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.endif	# PY_PYTHONMAGICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-PythonMagick
