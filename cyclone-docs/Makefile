# $NetBSD$

GITHUB_PROJECT=	cyclone
GITHUB_TAG=	v0.27
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-docs-${DISTNAME:S,^v,,}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=justinethier/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://justinethier.github.io/cyclone/index
COMMENT=	Documentation for wip/cyclone
LICENSE=	mit

WRKSRC=		${WRKDIR}/cyclone-${PKGVERSION_NOREV}

INSTALLATION_DIRS+=	share/doc/cyclone
INSTALLATION_DIRS+=	share/examples/cyclone

# do nothing
do-configure:
do-build:

do-install:
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/doc/cyclone/{}" ";"
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DESTDIR}${PREFIX}/share/doc/cyclone/{}" ";"
	cd ${WRKSRC}/examples && ${FIND} . -type d -exec ${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/examples/cyclone/{}" ";"
	cd ${WRKSRC}/examples && ${FIND} . -type f -exec ${INSTALL_DATA} "{}" "${DESTDIR}${PREFIX}/share/examples/cyclone/{}" ";"

.include "../../mk/bsd.pkg.mk"
