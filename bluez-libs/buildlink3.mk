# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	bluez-libs

BUILDLINK_API_DEPENDS.bluez-libs+=	bluez-libs>=3.0
BUILDLINK_PKGSRCDIR.bluez-libs?=	../../wip/bluez-libs
.endif # BLUEZ_LIBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-bluez-libs
