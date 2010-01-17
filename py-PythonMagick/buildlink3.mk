# $NetBSD: buildlink3.mk,v 1.2 2010/01/17 12:03:30 thomasklausner Exp $

BUILDLINK_TREE+=	py26-PythonMagick

.if !defined(PY26_PYTHONMAGICK_BUILDLINK3_MK)
PY26_PYTHONMAGICK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-PythonMagick+=	py26-PythonMagick>=0.9.1
BUILDLINK_ABI_DEPENDS.py26-PythonMagick?=	py26-PythonMagick>=0.9.1nb1
BUILDLINK_PKGSRCDIR.py26-PythonMagick?=	../../wip/py-PythonMagick

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../devel/boost-python/buildlink3.mk"
.endif	# PY26_PYTHONMAGICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-PythonMagick
