# $NetBSD: buildlink3.mk,v 1.2 2011/05/27 03:22:19 schnoebe Exp $

BUILDLINK_TREE+=	pyconstruct

.if !defined(PY_CONSTRUCT_BUILDLINK3_MK)
PY_CONSTRUCT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyconstruct+=	${PYPKGPREFIX}-construct>=2.04
BUILDLINK_PKGSRCDIR.pyconstruct?=	../../wip/py-construct

.endif # PY_CONSTRUCT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyconstruct
