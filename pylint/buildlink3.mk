# $NetBSD: buildlink3.mk,v 1.2 2010/04/05 16:09:40 helgoman Exp $

BUILDLINK_TREE+=	pylint

.if !defined(PYLINT_BUILDLINK3_MK)
PYLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pylint+=	pylint>=0.20.0nb1
BUILDLINK_PKGSRCDIR.pylint?=	../../wip/pylint
.endif	# PYLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylint
