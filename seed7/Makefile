# $NetBSD$

DISTNAME=	Seed7_release_2025-05-16
PKGNAME=	seed7-20250516
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=ThomasMertes/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://seed7.sourceforce.net/
COMMENT=	General purpose programming language
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_TOOLS+=	gmake

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	AR=${AR:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/seed7 share/examples/seed7

do-configure:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} depend

do-build:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} s7 s7c utils

do-test:
	cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} test

do-install:
.for x in db7 diff7 find7 ftp7 ide7 portfwd7 pv7 s7 s7c sql7 sydir7
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${x} ${DESTDIR}${PREFIX}/bin/
.endfor
.for x in bigfiles ftpserv hd which toutf8
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${x} ${DESTDIR}${PREFIX}/bin/s7-${x}
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/prg/*.sd7 ${DESTDIR}${PREFIX}/share/examples/seed7/
	${INSTALL_DATA} ${WRKSRC}/doc/*.{txt,htm,css,vim,nanorc,syn,uew,xml} ${DESTDIR}${PREFIX}/share/doc/seed7/

.include "../../mk/bsd.pkg.mk"
