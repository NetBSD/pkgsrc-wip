# $NetBSD: buildlink3.mk,v 1.4 2013/01/31 20:46:31 noud4 Exp $

BUILDLINK_TREE+=	libssh

.if !defined(LIBSSH_BUILDLINK3_MK)
LIBSSH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh+=	libssh>=0.5.4
BUILDLINK_ABI_DEPENDS.libssh+=	libssh>=0.5.4
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
