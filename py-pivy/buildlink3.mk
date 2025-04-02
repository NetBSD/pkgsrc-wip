# $NetBSD: $

BUILDLINK_TREE+=	py-pivy

.if !defined(PY_PIVY_BUILDLINK3_MK)
PY_PIVY_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pivy+=	${PYPKGPREFIX}-pivy>=0.6
BUILDLINK_ABI_DEPENDS.py-pivy+=	${PYPKGPREFIX}-pivy>=0.6

BUILDLINK_PKGSRCDIR.py-pivy?=		../../wip/py-pivy

.endif # PY_PIVY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pivy
