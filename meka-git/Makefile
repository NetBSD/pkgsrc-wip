# $NetBSD$

DISTNAME=	meka-0.80alpha0
CATEGORIES=	emulators
#GITHUB_TAG=	2ea7d721a6c8adf4d1c2a70303fa529810b2d72e
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocornut/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://smspower.org/
COMMENT=	Meka is a multi-machine 8 bit emulator
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	nasm>=2.0:../../devel/nasm

BUILD_TARGET=	exe

GIT_REPOSITORIES=	meka
GIT_REPO.meka=		git://github.com/ocornut/meka

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax pkg-config

WRKSRC=		${WRKDIR}/meka

BUILD_DIRS=		meka/srcs
INSTALLATION_DIRS=	bin share/doc/meka share/meka

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meka/meka ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/meka/meka.blt ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.dat ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.inp ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.msg ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.nam ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.pat ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.thm ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/icons.zip ${DESTDIR}${PREFIX}/share/meka
	cd ${WRKSRC}/meka && ${PAX} -pp -rw Data Themes ${DESTDIR}${PREFIX}/share/meka
	${INSTALL_DATA} ${WRKSRC}/meka/meka.txt ${DESTDIR}${PREFIX}/share/doc/meka
	${INSTALL_DATA} ${WRKSRC}/meka/changes.txt ${DESTDIR}${PREFIX}/share/doc/meka
	${INSTALL_DATA} ${WRKSRC}/meka/compat.txt ${DESTDIR}${PREFIX}/share/doc/meka
	${INSTALL_DATA} ${WRKSRC}/meka/debugger.txt ${DESTDIR}${PREFIX}/share/doc/meka
	${INSTALL_DATA} ${WRKSRC}/meka/multi.txt ${DESTDIR}${PREFIX}/share/doc/meka
	${INSTALL_DATA} ${WRKSRC}/meka/tech.txt ${DESTDIR}${PREFIX}/share/doc/meka

#.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/allegro52/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
