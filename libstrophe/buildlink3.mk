# $NetBSD$

BUILDLINK_TREE+=	libstrophe

.if !defined(LIBSTROPHE_BUILDLINK3_MK)
LIBSTROPHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libstrophe+=	libstrophe>=0.8.8
BUILDLINK_PKGSRCDIR.libstrophe?=	../../wip/libstrophe

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# LIBSTROPHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libstrophe
