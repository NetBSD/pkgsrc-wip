# $NetBSD$

DEPENDS+=	pkg_install>=20170419:../../pkgtools/pkg_install

DISTNAME=	basepkg-1.1
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=user340/}

MAINTAINER=	mail@e-yuuki.org
HOMEPAGE=	https://github.com/user340/
COMMENT=	Packaging NetBSD Base System
LICENSE=	2-clause-bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/basepkg-1.1
USE_LANGUAGES=	# none
USE_TOOLS+= pax

INSTALLATION_DIRS+=	share/basepkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/basepkg.sh ${DESTDIR}${PREFIX}/share/basepkg
	${INSTALL_SCRIPT} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/basepkg
	${INSTALL_DATA} ${WRKSRC}/sets/comments ${DESTDIR}${PREFIX}/share/basepkg/sets
	${INSTALL_DATA} ${WRKSRC}/sets/deps ${DESTDIR}${PREFIX}/share/basepkg/sets
	${INSTALL_DATA} ${WRKSRC}/sets/descrs ${DESTDIR}${PREFIX}/share/basepkg/sets
	${INSTALL_DATA} ${WRKSRC}/sets/install ${DESTDIR}${PREFIX}/share/basepkg/sets
	${INSTALL_DATA} ${WRKSRC}/sets/deinstall ${DESTDIR}${PREFIX}/share/basepkg/sets
	cd ${WRKSRC}/sets && ${PAX} -wr lists ${DESTDIR}${PREFIX}/share/basepkg/sets

.include "../../mk/bsd.pkg.mk"
