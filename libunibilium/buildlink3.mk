# $NetBSD: buildlink3.mk,v 1.1 2015/02/21 16:20:18 jonthn Exp $
BUILDLINK_TREE+=	libunibilium

.if !defined(LIBUNIBILIUM_BUILDLINK3_MK)
LIBUNIBILIUM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunibilium+=	libunibilium>=2.0.0
BUILDLINK_PKGSRCDIR.libunibilium?=	../../wip/libunibilium
.endif	# LIBUNIBILIUM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunibilium
