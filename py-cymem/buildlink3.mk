# $NetBSD$

BUILDLINK_DEPMETHOD.py-cymem?=	build

BUILDLINK_TREE+=	py-cymem

.if !defined(PY_CYMEM_BUILDLINK3_MK)
PY_CYMEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-cymem+=	${PYPKGPREFIX}-cymem>=2.0.5
BUILDLINK_PKGSRCDIR.py-cymem?=	../../wip/py-cymem

.include "../../devel/py-cython/buildlink3.mk"
.endif	# PY_CYMEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cymem
