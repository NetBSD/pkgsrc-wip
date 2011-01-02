# $NetBSD: buildlink3.mk,v 1.4 2011/01/02 21:47:10 helgoman Exp $

BUILDLINK_TREE+=	pylint

.if !defined(PYLINT_BUILDLINK3_MK)
PYLINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pylint+=	pylint>=0.22.0
BUILDLINK_PKGSRCDIR.pylint?=	../../wip/pylint
.endif	# PYLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylint
