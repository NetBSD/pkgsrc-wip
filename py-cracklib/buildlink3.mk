# $NetBSD$

BUILDLINK_TREE+=	py27-cracklib

.if !defined(PY27_CRACKLIB_BUILDLINK3_MK)
PY27_CRACKLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-cracklib+=	py27-cracklib>=2.9.0
BUILDLINK_PKGSRCDIR.py27-cracklib?=	../../wip/py-cracklib
.endif	# PY27_CRACKLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-cracklib
