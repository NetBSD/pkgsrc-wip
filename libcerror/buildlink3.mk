# $NetBSD: buildlink3.mk,v 1.3 2013/05/28 12:14:20 othyro Exp $

BUILDLINK_TREE+=	libcerror

.if !defined(LIBCERROR_BUILDLINK3_MK)
LIBCERROR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcerror+=	libcerror>=20121222
BUILDLINK_PKGSRCDIR.libcerror?=		../../wip/libcerror

.endif	# LIBCERROR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcerror
