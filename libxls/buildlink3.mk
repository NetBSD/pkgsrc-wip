# $NetBSD$

BUILDLINK_TREE+=	libxls

.if !defined(LIBXLS_BUILDLINK3_MK)
LIBXLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxls+=	libxls>=1.5.0rc0
BUILDLINK_PKGSRCDIR.libxls?=	../../wip/libxls

.include "../../converters/libiconv/buildlink3.mk"
.endif

BUILDLINK_TREE+=	-libxls
