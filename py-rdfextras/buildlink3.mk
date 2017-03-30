# $NetBSD$

BUILDLINK_TREE+=	py27-rdfextras

.if !defined(PY27_RDFEXTRAS_BUILDLINK3_MK)
PY27_RDFEXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-rdfextras+=	py27-rdfextras>=0.4
BUILDLINK_PKGSRCDIR.py27-rdfextras?=	../../wip/py-rdfextras
.endif	# PY27_RDFEXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-rdfextras
