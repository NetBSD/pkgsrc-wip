# $NetBSD: buildlink3.mk,v 1.1 2014/12/04 23:05:13 othyro Exp $

BUILDLINK_TREE+=	libcstring

.if !defined(LIBCSTRING_BUILDLINK3_MK)
LIBCSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcstring+=	libcstring>=20141018
BUILDLINK_PKGSRCDIR.libcstring?=	../../wip/libcstring

.endif	# LIBCSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcstring
