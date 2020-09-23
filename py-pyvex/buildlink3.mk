# $NetBSD: buildlink3.mk,v 1.1 2018/03/15 02:49:25 khorben Exp $

BUILDLINK_TREE+=	py-pyvex

.if !defined(PY_PYVEX_BUILDLINK3_MK)
PY_PYVEX_BUILDLINK3_MK:=

.include "../../wip/py-angr/version.mk"
BUILDLINK_API_DEPENDS.py-pyvex+=	${PYPKGPREFIX}-pyvex>=${ANGR_VERSION}
BUILDLINK_PKGSRCDIR.py-pyvex?=		../../wip/py-pyvex
.endif  # PY_PYVEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pyvex
