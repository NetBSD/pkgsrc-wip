# $NetBSD: buildlink3.mk,v 1.1 2009/07/04 19:26:21 milosn Exp $

BUILDLINK_TREE+=	io-range

.if !defined(IORANGE_BUILDLINK3_MK)
IORANGE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.io-range+=	io-range>=2013.12.04
BUILDLINK_PKGSRCDIR.io-range?=		../../wip/io-range

BUILDLINK_LIBDIRS.io-range+=		lib/io/addons/Range/_build/dll
BUILDLINK_INCDIRS.io-range+=		include/io/Range
.endif # IORANGE_BUILDLINK3_MK

BUILDLINK_TREE+=	-io-range
