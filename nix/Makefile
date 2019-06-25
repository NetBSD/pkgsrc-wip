# $NetBSD$

DISTNAME=	nix-2.2.2
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=NixOS/}

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://github.com/NixOS/nix/
COMMENT=	Purely functional package manager
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config yacc flex automake autoconf autoreconf #bison?
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES

PKGCONFIG_OVERRIDE+=	src/libexpr/nix-expr.pc.in
PKGCONFIG_OVERRIDE+=	src/libmain/nix-main.pc.in
PKGCONFIG_OVERRIDE+=	src/libstore/nix-store.pc.in

CONFIGURE_ARGS+=	--with-sandbox-shell=/bin/sh
CONFIGURE_ARGS+=	--enable-gc
CONFIGURE_ARGS+=	--disable-s3
#CONFIGURE_ARGS+=	--localstatedir=

CONFIGURE_ENV+=		EDITLINE_CFLAGS=${BUILDLINK_PREFIX.editlinereadline:Q}/include
CONFIGURE_ENV+=		EDITLINE_LIBS=${BUILDLINK_PREFIX.editlinereadline:Q}/lib
CONFIGURE_ENV+=		LIBLZMA_CFLAGS=${BUILDLINK_PREFIX.lzmalib:Q}/include
CONFIGURE_ENV+=		LIBLZMA_LIBS=${BUILDLINK_PREFIX.lzmalib:Q}/lib

pre-configure:
	cd ${WRKSRC} && ${SH} bootstrap.sh

.include "../../archivers/lzmalib/buildlink3.mk"
.include "../../archivers/brotli/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/editline/buildlink3.mk"
#.include "../../meta-pkgs/boost/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
