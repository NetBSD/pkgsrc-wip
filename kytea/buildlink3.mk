# $NetBSD: buildlink3.mk,v 1.1 2013/08/01 01:51:25 othyro Exp $

BUILDLINK_TREE+=	kytea

.if !defined(KYTEA_BUILDLINK3_MK)
KYTEA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kytea+=	kytea>=0.4.6
BUILDLINK_PKGSRCDIR.kytea?=	../../wip/kytea
.endif	# KYTEA_BUILDLINK3_MK

BUILDLINK_TREE+=	-kytea
