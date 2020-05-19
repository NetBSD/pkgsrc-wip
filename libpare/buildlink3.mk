# $NetBSD: buildlink3.mk,v 1.2 2013/08/14 01:33:35 outpaddling Exp $

BUILDLINK_TREE+=	libpare

.if !defined(LIBPARE_BUILDLINK3_MK)
LIBPARE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpare+=	libpare>=1.1.1
BUILDLINK_PKGSRCDIR.libpare?=	../../wip/libpare
BUILDLINK_DEPMETHOD.libpare?=	build
.endif	# LIBPARE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpare
