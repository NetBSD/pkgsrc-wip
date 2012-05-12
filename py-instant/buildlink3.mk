# $NetBSD: buildlink3.mk,v 1.4 2012/05/12 14:33:39 outpaddling Exp $

BUILDLINK_TREE+=	instant

.if !defined(PY_INSTANT_BUILDLINK3_MK)
PY_INSTANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.instant+=	${PYPKGPREFIX}-instant>=1.0.0
BUILDLINK_PKGSRCDIR.instant?=	../../wip/py-instant
.endif	# PY_INSTANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-instant
