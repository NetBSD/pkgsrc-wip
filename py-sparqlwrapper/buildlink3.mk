# $NetBSD$

BUILDLINK_TREE+=	py27-sparqlwrapper

.if !defined(PY27_SPARQLWRAPPER_BUILDLINK3_MK)
PY27_SPARQLWRAPPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-sparqlwrapper+=	py27-sparqlwrapper>=1.6.2
BUILDLINK_PKGSRCDIR.py27-sparqlwrapper?=	../../wip/py-sparqlwrapper
.endif	# PY27_SPARQLWRAPPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-sparqlwrapper
