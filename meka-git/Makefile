# $NetBSD$

DISTNAME=	meka-0.72
CATEGORIES= 	emulators
#GITHUB_TAG=	2ea7d721a6c8adf4d1c2a70303fa529810b2d72e
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocornut/}

MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://smspower.org/
COMMENT=	Meka is a multi-machine 8 bit emulator
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	nasm>=2.0:../../devel/nasm

BUILD_TARGET=	exe

GIT_REPOSITORIES=	meka
GIT_REPO.meka=	git://github.com/ocornut/meka

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gmake

WRKSRC=		${WRKDIR}/meka

BUILD_DIRS=	meka/srcs
INSTALLATION_DIRS=	bin

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Replace hardcoded paths
SUBST_FILES.fix-paths=		meka/srcs/Makefile
SUBST_SED.fix-paths=		-e 's,"/usr/local,"${PREFIX},g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/meka/meka ${DESTDIR}${PREFIX}/bin

#.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/allegro52/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
