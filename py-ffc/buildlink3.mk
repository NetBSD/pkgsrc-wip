# $NetBSD: buildlink3.mk,v 1.5 2013/03/23 13:33:57 outpaddling Exp $

BUILDLINK_TREE+=	py-ffc

.if !defined(PY_FFC_BUILDLINK3_MK)
PY_FFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-ffc+=	${PYPKGPREFIX}-ffc>=1.0.0
BUILDLINK_PKGSRCDIR.py-ffc?=	../../wip/py-ffc
.endif	# PY_FFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-ffc
