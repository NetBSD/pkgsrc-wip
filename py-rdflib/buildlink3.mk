# $NetBSD: buildlink3.mk,v 1.2 2013/02/16 12:07:34 thomasklausner Exp $

BUILDLINK_TREE+=	py-rdflib

.if !defined(PY27_RDFLIB_BUILDLINK3_MK)
PY27_RDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-rdflib+=	${PYPKGPREFIX}-rdflib>=3.1.0
BUILDLINK_PKGSRCDIR.py-rdflib?=	../../wip/py-rdflib
.endif	# PY27_RDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-rdflib
