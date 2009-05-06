# $NetBSD: buildlink3.mk,v 1.9 2009/05/06 09:13:58 cheusov Exp $

BUILDLINK_TREE+=	bluez-libs

BUILDLINK_API_DEPENDS.bluez-libs+=	bluez-libs>=3.0
BUILDLINK_PKGSRCDIR.bluez-libs?=	../../wip/bluez-libs

BUILDLINK_TREE+=	-bluez-libs
