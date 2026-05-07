# $NetBSD$

DISTNAME=	bob-0.99.4
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=jperkin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jperkin@pkgsrc.org
HOMEPAGE=	https://github.com/jperkin/bob
COMMENT=	Fast, robust, powerful, and user-friendly package builder
LICENSE=	isc

LUASRC_REV=	178af5ab1dd388fd378cb9cb24d65747e08f5a5e
LUASRC_TGZ=	lua-src-${LUASRC_REV}.tar.gz

SYSSTAT_REV=	2a12cb8de6732366bb7764b84296f53f9be00143
SYSSTAT_TGZ=	systemstat-${SYSSTAT_REV}.tar.gz

DISTFILES=	${DEFAULT_DISTFILES} ${LUASRC_TGZ} ${SYSSTAT_TGZ}

SITES.${LUASRC_TGZ}=	-${MASTER_SITE_GITHUB:=mlua-rs/}lua-src-rs/archive/${LUASRC_REV}.tar.gz
SITES.${SYSSTAT_TGZ}=	-${MASTER_SITE_GITHUB:=jperkin/}systemstat/archive/${SYSSTAT_REV}.tar.gz

RUST_REQ=	1.86.0

BOB_DATADIR?=	${VARBASE}/db/bob
EGDIR=		${PREFIX}/share/examples/bob
BUILD_DEFS+=	BOB_DATADIR VARBASE

INSTALLATION_DIRS+=	${EGDIR}
PKG_SYSCONFSUBDIR=	bob

CONF_FILES=	${EGDIR}/config.lua ${PKG_SYSCONFDIR}/config.lua
OWN_DIRS=	${BOB_DATADIR} ${PKG_SYSCONFDIR}

MAKE_ENV+=	BOB_DATADIR=${BOB_DATADIR:Q}
MAKE_ENV+=	BOB_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

post-build:
	${RUN} cd ${WRKSRC} && ./target/release/bob -c example.lua init

post-install:
	${INSTALL_DATA} ${WRKSRC}/example.lua ${DESTDIR}${EGDIR}/config.lua

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
