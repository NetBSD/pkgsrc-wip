# $NetBSD$

DISTNAME=	cyclone-${GITHUB_TAG:S,^v,,}
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=justinethier/}
GITHUB_TAG=	v0.36.0

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://justinethier.github.io/cyclone/
COMMENT=	Scheme-to-C compiler
LICENSE=	mit

USE_TOOLS+=	pkg-config
USE_TOOLS+=	gmake
TEST_TARGET=	test

INSTALLATION_DIRS+=	share/doc/cyclone
INSTALLATION_DIRS+=	share/examples/cyclone

PKGCONFIG_OVERRIDE+=	third-party/libtommath-1.2.0/libtommath.pc.in

post-install:
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/doc/cyclone/{}" ";"
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec \
		${INSTALL_DATA} "{}" "${DESTDIR}${PREFIX}/share/doc/cyclone/{}" ";"
	cd ${WRKSRC}/examples && ${FIND} . -type d -exec \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/examples/cyclone/{}" ";"
	cd ${WRKSRC}/examples && ${FIND} . -type f -exec \
		${INSTALL_DATA} "{}" "${DESTDIR}${PREFIX}/share/examples/cyclone/{}" ";"

.include "../../devel/concurrencykit/buildlink3.mk"
.include "../../math/ltm/buildlink3.mk"
BUILDLINK_DEPMETHOD.cyclone-bootstrap=	build
.include "../../wip/cyclone-bootstrap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
