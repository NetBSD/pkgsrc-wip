# $NetBSD$

BUILDLINK_TREE+=	py-cracklib

.if !defined(PY_CRACKLIB_BUILDLINK3_MK)
PY_CRACKLIB_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-cracklib+=	${PYPKGPREFIX}-cracklib>=2.9.0
BUILDLINK_PKGSRCDIR.py-cracklib?=	../../wip/py-cracklib
.endif	# PY_CRACKLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cracklib
