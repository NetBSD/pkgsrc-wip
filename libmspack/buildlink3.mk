# $NetBSD: buildlink3.mk,v 1.1 2015/08/01 13:49:58 makoto Exp $

BUILDLINK_TREE+=	libmspack

.if !defined(LIBMSPACK_BUILDLINK3_MK)
LIBMSPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmspack+=	libmspack>=0.5alpha
BUILDLINK_PKGSRCDIR.libmspack?=		../../wip/libmspack

# Sorry, not for sure the following line
#.include "../../x11/gtk2/buildlink3.mk"
.endif	# LIBMSPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmspack
