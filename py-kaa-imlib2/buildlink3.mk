# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	py-kaa-imlib2

.if !defined(PY_KAA_IMLIB2_BUILDLINK3_MK)
PY_KAA_IMLIB2_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-kaa-imlib2+=	${PYPKGPREFIX}-kaa-imlib2>=0.2.3
BUILDLINK_PKGSRCDIR.py-kaa-imlib2?=	../../wip/py-kaa-imlib2

.include "../../wip/py-kaa-base/buildlink3.mk"
.endif # PY_KAA_IMLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kaa-imlib2
