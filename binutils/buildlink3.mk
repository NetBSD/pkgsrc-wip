# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/10/06 12:57:53 makoto Exp $

BUILDLINK_TREE+=	binutils

.if !defined(BINUTILS_BUILDLINK3_MK)
BINUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.binutils+=	binutils>=2.17
BUILDLINK_PKGSRCDIR.binutils?=	../../devel/binutils
BUILDLINK_DEPMETHOD.binutils?=	build
.endif # BINUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-binutils
