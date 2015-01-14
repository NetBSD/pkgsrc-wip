# $NetBSD: buildlink3.mk,v 1.1 2015/01/14 17:40:23 thomasklausner Exp $

BUILDLINK_TREE+=	libnettle

.if !defined(LIBNETTLE_BUILDLINK3_MK)
LIBNETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnettle+=	nettle>=2.4
BUILDLINK_PKGSRCDIR.libnettle?=		../../security/nettle

.include "../../devel/gmp/buildlink3.mk"
.endif # LIBNETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnettle
