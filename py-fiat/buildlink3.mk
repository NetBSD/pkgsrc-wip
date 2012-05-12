# $NetBSD: buildlink3.mk,v 1.4 2012/05/12 14:33:38 outpaddling Exp $

BUILDLINK_TREE+=	fiat

.if !defined(PY_FIAT_BUILDLINK3_MK)
PY_FIAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.fiat+=	${PYPKGPREFIX}-fiat>=1.0.0
BUILDLINK_PKGSRCDIR.fiat?=	../../wip/py-fiat
.endif	# PY_FIAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-fiat
