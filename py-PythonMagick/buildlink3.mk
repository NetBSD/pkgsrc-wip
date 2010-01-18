# $NetBSD: buildlink3.mk,v 1.3 2010/01/18 09:38:29 thomasklausner Exp $

BUILDLINK_TREE+=	py-PythonMagick

.if !defined(PY_PYTHONMAGICK_BUILDLINK3_MK)
PY_PYTHONMAGICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-PythonMagick+=	${PYPKGPREFIX}-PythonMagick>=0.9.1
BUILDLINK_ABI_DEPENDS.py-PythonMagick?=	${PYPKGPREFIX}-PythonMagick>=0.9.1nb2
BUILDLINK_PKGSRCDIR.py-PythonMagick?=	../../wip/py-PythonMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.endif	# PY_PYTHONMAGICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-PythonMagick
