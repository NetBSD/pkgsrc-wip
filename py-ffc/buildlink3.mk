# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 16:31:31 outpaddling Exp $

BUILDLINK_TREE+=	py26-ffc

.if !defined(PY26_FFC_BUILDLINK3_MK)
PY26_FFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-ffc+=	py26-ffc>=1.0.0
BUILDLINK_PKGSRCDIR.py26-ffc?=	../../wip/py-ffc
.endif	# PY26_FFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-ffc
