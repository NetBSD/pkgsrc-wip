# $NetBSD: buildlink3.mk,v 1.2 2013/06/09 22:01:57 othyro Exp $

BUILDLINK_TREE+=	libcpath

.if !defined(LIBCPATH_BUILDLINK3_MK)
LIBCPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcpath+=	libcpath>=20121225
BUILDLINK_PKGSRCDIR.libcpath?=		../../wip/libcpath

.include "../../wip/libuna/buildlink3.mk"
.include "../../wip/libcsplit/buildlink3.mk"
.include "../../wip/libclocale/buildlink3.mk"
.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcpath
