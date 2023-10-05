# $NetBSD$

DISTNAME=	chirpstack-4.5.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=chirpstack/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://www.chirpstack.io/
COMMENT=	Open-source LoRaWAN Network Server
LICENSE=	mit

TOOL_DEPENDS+=	yarn-[0-9]*:../../devel/yarn

USE_TOOLS=	pax pkg-config
USE_LANGUAGES=	c c++

PKG_SYSCONFSUBDIR=	chirpstack
EGDIR=			${PREFIX}/share/examples/chirpstack

.include "cargo-depends.mk"
CARGO_WRKSRC=	${WRKSRC}/chirpstack

.include "conf-files.mk"
.for file in ${CHIRPSTACK_CONF_FILES}
CONF_FILES+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file}
.endfor

RCD_SCRIPTS+=	chirpstack

pre-build:
	${RUN} cd ${WRKSRC}/ui && ${SETENV} ${MAKE_ENV} ${MAKE}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${CARGO_WRKSRC}/configuration && ${FIND} . -type f -name '*.toml' -print | \
		${PAX} -rw ${DESTDIR}${EGDIR}

.include "../../lang/rust/cargo.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
