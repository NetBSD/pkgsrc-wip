# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	py-kaa-base

.if !defined(PY_KAA_BASE_BUILDLINK3_MK)
PY_KAA_BASE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-kaa-base+=	${PYPKGPREFIX}-kaa-base>=0.3.0
BUILDLINK_PKGSRCDIR.py-kaa-base?=	../../wip/py-kaa-base
.endif # PY_KAA_BASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kaa-base
