# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	py-kaa-metadata

.if !defined(PY_KAA_METADATA_BUILDLINK3_MK)
PY_KAA_METADATA_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"
BUILDLINK_API_DEPENDS.py-kaa-metadata+=	${PYPKGPREFIX}-kaa-metadata>=0.7.2
BUILDLINK_PKGSRCDIR.py-kaa-metadata?=	../../wip/py-kaa-metadata

.include "../../wip/py-kaa-base/buildlink3.mk"
.endif # PY_KAA_METADATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-kaa-metadata
