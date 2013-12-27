# $NetBSD: buildlink3.mk,v 1.1 2013/12/27 03:09:35 makoto Exp $

BUILDLINK_TREE+=	cross-binutils

.if !defined(CROSS_BINUTILS_BUILDLINK3_MK)
CROSS_BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cross-binutils+=	cross-binutils>=2.17.0.0
BUILDLINK_PKGSRCDIR.cross-binutils?=	../../cross/binutils
.endif # CROSS_BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-cross-binutils
