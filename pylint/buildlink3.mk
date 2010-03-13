# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/13 13:05:44 helgoman Exp $

BUILDLINK_TREE+=	pylint

.if !defined(PYLINT_BUILDLINK3_MK)
PYLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pylint+=	pylint>=0.19.0nb1
BUILDLINK_PKGSRCDIR.pylint?=	../../wip/pylint
.endif	# PYLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylint
