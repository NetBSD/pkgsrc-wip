# $NetBSD: buildlink3.mk,v 1.19 2022/09/11 12:51:04 wiz Exp $

BUILDLINK_TREE+=	sonic

.if !defined(SONIC_BUILDLINK3_MK)
SONIC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.sonic+=	sonic>=0.2.0
BUILDLINK_ABI_DEPENDS.sonic+=	sonic>=0.2.0
BUILDLINK_PKGSRCDIR.sonic?=	../../audio/sonic

.endif # SONIC_BUILDLINK3_MK

BUILDLINK_TREE+=	-sonic
