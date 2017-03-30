# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.16.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.py27-rdflib?=	build

BUILDLINK_TREE+=	py27-rdflib

.if !defined(PY27_RDFLIB_BUILDLINK3_MK)
PY27_RDFLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-rdflib+=	py27-rdflib>=3.4.0
BUILDLINK_PKGSRCDIR.py27-rdflib?=	../../wip/py-rdflib340
.endif	# PY27_RDFLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-rdflib
