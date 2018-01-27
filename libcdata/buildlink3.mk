# $NetBSD: buildlink3.mk,v 1.1 2013/06/08 12:37:42 othyro Exp $

BUILDLINK_TREE+=	libcdata

.if !defined(LIBCDATA_BUILDLINK3_MK)
LIBCDATA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdata+=	libcdata>=20130407
BUILDLINK_PKGSRCDIR.libcdata?=		../../wip/libcdata

.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdata
