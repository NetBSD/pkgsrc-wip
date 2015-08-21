# $NetBSD: buildlink3.mk,v 1.1 2015/08/21 14:57:57 khorben Exp $

BUILDLINK_TREE+=	py_radare2

.if !defined(PY_RADARE2_BUILDLINK3_MK)
PY_RADARE2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py_radare2+=	${PYPKGPREFIX}-radare2>=0.9.9
BUILDLINK_ABI_DEPENDS.py_radare2+=	${PYPKGPREFIX}-radare2>=0.9.9
BUILDLINK_PKGSRCDIR.py_radare2?=	../../wip/py-radare2

.include "../../devel/radare2/buildlink3.mk"
.endif # PY_RADARE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py_radare2
