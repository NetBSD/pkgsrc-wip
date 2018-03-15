# $NetBSD$

BUILDLINK_TREE+=	py-pyvex

.if !defined(PY_PYVEX_BUILDLINK3_MK)
PY_PYVEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pyvex+=	${PYPKGPREFIX}-pyvex>=7.8.2.21
BUILDLINK_PKGSRCDIR.py-pyvex?=		../../wip/py-pyvex

. include "../../emulators/unicorn/buildlink3.mk"
.endif  # PY_PYVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyvex
