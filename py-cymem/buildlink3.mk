# $NetBSD$

BUILDLINK_DEPMETHOD.py38-cymem?=	build

BUILDLINK_TREE+=	py38-cymem

.if !defined(PY38_CYMEM_BUILDLINK3_MK)
PY38_CYMEM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py38-cymem+=	py38-cymem>=2.0.5
BUILDLINK_PKGSRCDIR.py38-cymem?=	../../wip/py-cymem

.include "../../devel/py-cython/buildlink3.mk"
.endif	# PY38_CYMEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-py38-cymem
