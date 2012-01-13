# $NetBSD: buildlink3.mk,v 1.1 2012/01/13 21:55:46 jihbed Exp $

BUILDLINK_TREE+=	py27-rdflib

.if !defined(PY27_RDFLIB_BUILDLINK3_MK)
PY27_RDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-rdflib+=	py27-rdflib>=3.1.0
BUILDLINK_PKGSRCDIR.py27-rdflib?=	../../wip/py-rdflib
.endif	# PY27_RDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-rdflib
