# $NetBSD$

BUILDLINK_TREE+=	libpsl

.if !defined(LIBPSL_BUILDLINK3_MK)
LIBPSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpsl+=	libpsl>=0.20.2
BUILDLINK_PKGSRCDIR.libpsl?=	../../wip/libpsl

#.include "../../textproc/icu/buildlink3.mk"
.endif	# LIBPSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpsl
