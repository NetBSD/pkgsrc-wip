# $NetBSD: buildlink3.mk,v 1.8 2012/12/30 19:25:18 roelants Exp $

BUILDLINK_TREE+=	eina

.if !defined(EINA_BUILDLINK3_MK)
EINA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.eina+=	eina>=1.7.0
BUILDLINK_PKGSRCDIR.eina?=	../../wip/eina
.endif	# EINA_BUILDLINK3_MK

BUILDLINK_TREE+=	-eina
