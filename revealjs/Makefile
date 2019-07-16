# $NetBSD$

VERSION=	3.8.0
DISTNAME=	reveal.js-${VERSION}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hakimel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hakimel/reveal.js/
COMMENT=	Presentation tool with html/css
LICENSE=	mit

NO_BUILD=	yes

INSTALL_DIR=	${PREFIX}/share/

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_FILES.path=	test/examples/*.html

SUBST_SED.path=		-e "s|href=\"\.\.\/\.\.\/|href=\"${INSTALL_DIR}${PKGNAME}/|"
SUBST_SED.path+=	-e   "s|src=\"\.\.\/\.\.\/|src=\"${INSTALL_DIR}${PKGNAME}/|"
SUBST_SED.path+=	-e "s|src: \'\.\.\/\.\.\/|src: \'${INSTALL_DIR}${PKGNAME}/|"

do-install:
	mkdir ${DESTDIR}${PREFIX}/share/revealjs/
	${CP} -pr ${WRKSRC} ${DESTDIR}${PREFIX}/share/
	find ${DESTDIR}${PREFIX}/share/${PKGNAME}/lib    -type f -perm 0755 -exec chmod -x '{}' \;
	find ${DESTDIR}${PREFIX}/share/${PKGNAME}/plugin -type f -perm 0755 -exec chmod -x '{}' \;

.include "../../mk/bsd.pkg.mk"
