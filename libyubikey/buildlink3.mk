# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/03/26 13:25:36 marttikuparinen Exp $

BUILDLINK_TREE+=	libyubikey

.if !defined(LIBYUBIKEY_BUILDLINK3_MK)
LIBYUBIKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyubikey+=	libyubikey>=1.5
BUILDLINK_PKGSRCDIR.libyubikey?=	../../wip/libyubikey
.endif	# LIBYUBIKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyubikey
