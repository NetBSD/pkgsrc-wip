# $NetBSD: buildlink3.mk,v 1.1 2013/05/29 03:01:04 othyro Exp $

BUILDLINK_TREE+=	libclocale

.if !defined(LIBCLOCALE_BUILDLINK3_MK)
LIBCLOCALE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclocale+=	libclocale>=20121224
BUILDLINK_PKGSRCDIR.libclocale?=	../../wip/libclocale

.include "../../wip/libcerror/buildlink3.mk"
.endif	# LIBCLOCALE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclocale
