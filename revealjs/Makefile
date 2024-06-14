# $NetBSD$

VERSION=	5.1.0
DISTNAME=	reveal.js-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hakimel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hakimel/reveal.js/
COMMENT=	Presentation tool with html/css
LICENSE=	mit

USE_TOOLS+=	pax

NO_BUILD=	yes

INSTALL_DIR=	${PREFIX}/share/

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	examples/*.html

SUBST_SED.path=		-e "s|href=\"\.\.\/|href=\"${INSTALL_DIR}${PKGNAME}/|"
SUBST_SED.path+=	-e   "s|src=\"\.\.\/|src=\"${INSTALL_DIR}${PKGNAME}/|"
SUBST_SED.path+=	-e "s|src: '\.\.\/|src: '${INSTALL_DIR}${PKGNAME}/|"

INSTALLATION_DIRS+=	share/${PKGNAME}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/${PKGNAME}

.include "../../mk/bsd.pkg.mk"
