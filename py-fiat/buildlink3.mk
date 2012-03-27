# $NetBSD: buildlink3.mk,v 1.2 2012/03/27 16:31:31 outpaddling Exp $

BUILDLINK_TREE+=	py26-fiat

.if !defined(PY26_FIAT_BUILDLINK3_MK)
PY26_FIAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-fiat+=	py26-fiat>=1.0.0
BUILDLINK_PKGSRCDIR.py26-fiat?=	../../wip/py-fiat
.endif	# PY26_FIAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-fiat
