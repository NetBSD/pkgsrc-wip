# $NetBSD: buildlink3.mk,v 1.1 2013/06/10 05:09:15 othyro Exp $

BUILDLINK_TREE+=	libre

.if !defined(LIBRE_BUILDLINK3_MK)
LIBRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libre+=	libre>=0.4.3
BUILDLINK_PKGSRCDIR.libre?=	../../wip/libre
.endif	# LIBRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libre
