# $NetBSD$

DISTNAME=	atuin-18.19.0
CATEGORIES=	sysutils shells
MASTER_SITES=	${MASTER_SITE_GITHUB:=atuinsh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://atuin.sh/
COMMENT=	Magical shell history (client and server)
LICENSE=	mit

WRKSRC=	${WRKDIR}/${DISTNAME}
MAKE_ENV+= CARGO_PROFILE_RELEASE_CODEGEN_UNITS=16
MAKE_ENV+= CARGO_PROFILE_RELEASE_LTO=thin

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config

BUILD_DEFS+=		VARBASE

ATUIN_USER?=			_atuin
ATUIN_GROUP?=			_atuin
PKG_GROUPS=			${ATUIN_GROUP}
PKG_USERS=			${ATUIN_USER}:${ATUIN_GROUP}
PKG_HOME.${ATUIN_USER}=		${VARBASE}/db/atuin_server
# atuin-server has no privilege-drop of its own; the rc.d script su(1)s to
# this user, so it needs a runnable shell (nologin would break su -c).
PKG_SHELL.${ATUIN_USER}=	${SH}

PKG_SYSCONFSUBDIR=	atuin

RCD_SCRIPTS=		atuin-serverd

EGDIR=			share/examples/atuin
INSTALLATION_DIRS+=	bin ${EGDIR}

OWN_DIRS_PERMS+=	${VARBASE}/db/atuin_server \
			${ATUIN_USER} ${ATUIN_GROUP} 0750

CONF_FILES+=		${EGDIR}/server.toml ${PKG_SYSCONFDIR}/server.toml
CONF_FILES+=		${EGDIR}/config.toml ${PKG_SYSCONFDIR}/config.toml

FILES_SUBST+=		ATUIN_USER=${ATUIN_USER}
FILES_SUBST+=		ATUIN_GROUP=${ATUIN_GROUP}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/atuin ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/atuin-server ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${FILESDIR}/server.toml ${DESTDIR}${PREFIX}/${EGDIR}/server.toml
	${INSTALL_DATA} ${FILESDIR}/config.toml ${DESTDIR}${PREFIX}/${EGDIR}/config.toml

.include "cargo-depends.mk"

.include "../../security/openssl/buildlink3.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
