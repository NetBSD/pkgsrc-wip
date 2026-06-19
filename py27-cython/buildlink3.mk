# $NetBSD: buildlink3.mk,v 1.3 2017/01/25 16:09:06 adam Exp $

BUILDLINK_TREE+=	py27-cython

.if !defined(PY_CYTHON_BUILDLINK3_MK)
PY_CYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-cython+=	${PYPKGPREFIX}-cython>=0.12.1
BUILDLINK_PKGSRCDIR.py27-cython?=	../../wip/py27-cython
.endif	# PY_CYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-cython
