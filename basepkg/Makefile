# $NetBSD$

DISTNAME=	basepkg-1.5.3
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=user340/}

MAINTAINER=	uki@e-yuuki.org
HOMEPAGE=	https://github.com/user340/
COMMENT=	NetBSD system packages
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_install>=20170419:../../pkgtools/pkg_install

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

INSTALLATION_DIRS+=	basepkg basepkg/sets ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/basepkg.sh ${DESTDIR}${PREFIX}/basepkg
	${INSTALL_SCRIPT} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/basepkg
	${INSTALL_SCRIPT} ${WRKSRC}/README.html ${DESTDIR}${PREFIX}/basepkg
	${INSTALL_MAN} ${WRKSRC}/man/man1/basepkg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/basepkg.sh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/sets/comments ${DESTDIR}${PREFIX}/basepkg/sets/comments
	${INSTALL_DATA} ${WRKSRC}/sets/deps ${DESTDIR}${PREFIX}/basepkg/sets/deps
	${INSTALL_DATA} ${WRKSRC}/sets/descrs ${DESTDIR}${PREFIX}/basepkg/sets/descrs
	${INSTALL_DATA} ${WRKSRC}/sets/install ${DESTDIR}${PREFIX}/basepkg/sets/install
	${INSTALL_DATA} ${WRKSRC}/sets/deinstall ${DESTDIR}${PREFIX}/basepkg/sets/deinstall
	${INSTALL_DATA} ${WRKSRC}/sets/essentials ${DESTDIR}${PREFIX}/basepkg/sets/essentials
	cd ${WRKSRC}/sets && ${PAX} -wr lists ${DESTDIR}${PREFIX}/basepkg/sets

.include "../../mk/bsd.pkg.mk"
