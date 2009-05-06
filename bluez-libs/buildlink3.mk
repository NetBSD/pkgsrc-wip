# $NetBSD: buildlink3.mk,v 1.10 2009/05/06 09:23:45 cheusov Exp $

BUILDLINK_TREE+=	bluez-libs

.if !defined(BLUEZ_LIBS_BUILDLINK3_MK)
BLUEZ_LIBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bluez-libs+=	bluez-libs>=3.0
BUILDLINK_PKGSRCDIR.bluez-libs?=	../../wip/bluez-libs

.endif # BLUEZ_LIBS

BUILDLINK_TREE+=	-bluez-libs
