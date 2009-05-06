# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:12:52 cheusov Exp $

BUILDLINK_TREE+=	libnettle

.if !defined(LIBNETTLE_BUILDLINK3_MK)
LIBNETTLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libnettle+=	libnettle>=1.14
BUILDLINK_PKGSRCDIR.libnettle?=	../../wip/libnettle
.endif # LIBNETTLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libnettle
