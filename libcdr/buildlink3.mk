# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/04/22 16:06:42 ftigeot Exp $

BUILDLINK_TREE+=	libvisio

.if !defined(LIBVISIO_BUILDLINK3_MK)
LIBVISIO_BUILDLINK3_MK:=
BUILDLINK_API_DEPENDS.libvisio+=	libvisio>=0.0.15
BUILDLINK_PKGSRCDIR.libvisio?=		../../converters/libvisio
.endif

BUILDLINK_TREE+=	-libvisio
