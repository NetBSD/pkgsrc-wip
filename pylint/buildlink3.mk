# $NetBSD: buildlink3.mk,v 1.3 2010/08/19 05:06:14 helgoman Exp $

BUILDLINK_TREE+=	pylint

.if !defined(PYLINT_BUILDLINK3_MK)
PYLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pylint+=	pylint>=0.21.0nb1
BUILDLINK_PKGSRCDIR.pylint?=	../../wip/pylint
.endif	# PYLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylint
