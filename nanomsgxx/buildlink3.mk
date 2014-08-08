# $NetBSD: buildlink3.mk,v 1.1 2014/08/08 11:55:56 chybz Exp $

BUILDLINK_TREE+=	nanomsgxx

.if !defined(NANOMSGXX_BUILDLINK3_MK)
NANOMSGXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nanomsgxx+=	nanomsgxx>=0.1
BUILDLINK_PKGSRCDIR.nanomsgxx?=	../../devel/nanomsgxx
.endif	# NANOMSGXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-nanomsgxx
