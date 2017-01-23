# $NetBSD$

BUILDLINK_TREE+=	libmesode

.if !defined(LIBMESODE_BUILDLINK3_MK)
LIBMESODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmesode+=	libmesode>=0.9.1
BUILDLINK_PKGSRCDIR.libmesode?=		../../wip/libmesode-git

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBMESODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmesode
