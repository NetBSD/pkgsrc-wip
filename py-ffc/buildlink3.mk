# $NetBSD: buildlink3.mk,v 1.4 2012/05/12 14:33:38 outpaddling Exp $

BUILDLINK_TREE+=	ffc

.if !defined(PY_FFC_BUILDLINK3_MK)
PY_FFC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ffc+=	${PYPKGPREFIX}-ffc>=1.0.0
BUILDLINK_PKGSRCDIR.ffc?=	../../wip/py-ffc
.endif	# PY_FFC_BUILDLINK3_MK

BUILDLINK_TREE+=	-ffc
