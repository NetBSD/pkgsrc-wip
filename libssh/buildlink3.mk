# $NetBSD: buildlink3.mk,v 1.3 2013/01/31 14:59:28 noud4 Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.5.3
BUILDLINK_ABI_DEPENDS.libssh+=	libssh>=0.5.3
BUILDLINK_PKGSRCDIR.libssh?=	../../wip/libssh

pkgbase := libssh
.include "../../mk/pkg-build-options.mk"

PKG_OPTIONS?=		# empty
.if !empty(PKG_OPTIONS:Mzlib)
.include "../../devel/zlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mopenssl)
.include "../../security/openssl/buildlink3.mk"
.endif
.endif # LIBSSH_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh
