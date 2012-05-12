# $NetBSD: buildlink3.mk,v 1.3 2012/05/12 02:04:12 outpaddling Exp $

BUILDLINK_TREE+=	py26-instant

.if !defined(PY26_INSTANT_BUILDLINK3_MK)
PY26_INSTANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.instant+=	${PYPKGPREFIX}-instant>=1.0.0
BUILDLINK_PKGSRCDIR.instant?=	../../wip/py-instant
.endif	# PY26_INSTANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-instant
