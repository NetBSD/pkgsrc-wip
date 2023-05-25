# $NetBSD$

BUILDLINK_TREE+=	py-preshed

.if !defined(PY_PRESHED_BUILDLINK3_MK)
PY_PRESHED_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.py-preshed?=	build
BUILDLINK_API_DEPENDS.py-preshed+=	${PYPKGPREFIX}-preshed>=2.0.0nb1
BUILDLINK_PKGSRCDIR.py-preshed?=	../../wip/py-preshed
.endif	# PY_PRESHED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-preshed
