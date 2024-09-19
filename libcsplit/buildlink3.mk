# $NetBSD: buildlink3.mk,v 1.1 2013/06/08 12:24:12 othyro Exp $

BUILDLINK_TREE+=	libcsplit

.if !defined(LIBCSPLIT_BUILDLINK3_MK)
LIBCSPLIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcsplit+=	libcsplit>=20121224
BUILDLINK_PKGSRCDIR.libcsplit?=		../../wip/libcsplit

.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCSPLIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcsplit
