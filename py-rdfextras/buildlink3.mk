# $NetBSD$

BUILDLINK_TREE+=	py-rdfextras

.if !defined(PY_RDFEXTRAS_BUILDLINK3_MK)
PY_RDFEXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-rdfextras+=	${PYPKGPREFIX}-rdfextras>=0.4
BUILDLINK_PKGSRCDIR.py-rdfextras?=	../../wip/py-rdfextras
.endif	# PY_RDFEXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-rdfextras
