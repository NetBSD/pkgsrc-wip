# $NetBSD$

DISTNAME=	basepkg-1.7
CATEGORIES=	pkgtools
MASTER_SITES=	${MASTER_SITE_GITHUB:=user340/}

MAINTAINER=	uki@e-yuuki.org
HOMEPAGE=	https://github.com/user340/
COMMENT=	NetBSD system packages (Experimental stage of syspkg)
LICENSE=	2-clause-bsd

DEPENDS+=	pkg_install>=20191008:../../pkgtools/pkg_install

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

do-build:
	sed -e 's|^libbasepkg="./lib"|libbasepkg="${PREFIX}/basepkg/lib"|' ${WRKSRC}/basepkg.sh > ${WRKSRC}/basepkg.sh.new
	mv ${WRKSRC}/basepkg.sh.new ${WRKSRC}/basepkg.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/basepkg.sh ${DESTDIR}${PREFIX}/basepkg
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Command ${DESTDIR}${PREFIX}/basepkg/lib/Command
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Common ${DESTDIR}${PREFIX}/basepkg/lib/Common
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Logging ${DESTDIR}${PREFIX}/basepkg/lib/Logging
	${INSTALL_SCRIPT} ${WRKSRC}/lib/NetBSD ${DESTDIR}${PREFIX}/basepkg/lib/NetBSD
	${INSTALL_SCRIPT} ${WRKSRC}/lib/Package ${DESTDIR}${PREFIX}/basepkg/lib/Package
	${INSTALL_SCRIPT} ${WRKSRC}/lib/valid_MACHINE_ARCH ${DESTDIR}${PREFIX}/basepkg/lib/valid_MACHINE_ARCH
	${INSTALL_MAN} ${WRKSRC}/man/man1/basepkg.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/man1/basepkg.sh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/basepkg/README
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/basepkg/LICENSE
	${INSTALL_DATA} ${WRKSRC}/sets/install ${DESTDIR}${PREFIX}/basepkg/sets/install
	${INSTALL_DATA} ${WRKSRC}/sets/deinstall ${DESTDIR}${PREFIX}/basepkg/sets/deinstall
	${INSTALL_DATA} ${WRKSRC}/sets/essentials ${DESTDIR}${PREFIX}/basepkg/sets/essentials

.include "../../mk/bsd.pkg.mk"
