# $NetBSD: buildlink3.mk,v 1.5 2013/03/23 13:29:16 outpaddling Exp $

BUILDLINK_TREE+=	py-fiat

.if !defined(PY_FIAT_BUILDLINK3_MK)
PY_FIAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-fiat+=	${PYPKGPREFIX}-fiat>=1.0.0
BUILDLINK_PKGSRCDIR.py-fiat?=	../../wip/py-fiat
.endif	# PY_FIAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-fiat
