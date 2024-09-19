# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	python-taglib

.if !defined(PYTHON_TAGLIB_BUILDLINK3_MK)
PYTHON_TAGLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.python-taglib+=	${PYPKGPREFIX}-taglib>=1.3.3
BUILDLINK_PKGSRCDIR.python-taglib?=	../../wip/py-taglib
.endif # PYTHON_TAGLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-python-taglib
