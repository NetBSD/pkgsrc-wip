# $NetBSD$
#VERSION=	0.80
#PKGNAME=	meka-${VERSION}
CATEGORIES= 	emulators
#GHCOMMIT=	0ec668276ad207ec5cf3fecbac3f541a1b07f2a7
GHCOMMIT=	2ea7d721a6c8adf4d1c2a70303fa529810b2d72e
GITHUB_TAG=	${GHCOMMIT}
DISTNAME=	meka
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocornut/}
EXTRACT_SUFX=	.zip

LICENSE=	2-clause-bsd
COMMENT=	Meka is a multi-machine 8 bit emulator
MAINTAINER=	amoibos@gmail.com
HOMEPAGE=	http://smspower.org/

BUILD_TARGET=	exe

USE_LANGUAGES=	c c++

DIST_SUBDIR=	meka
WRKSRC=		${WRKDIR}/meka-${GHCOMMIT}/meka/srcs

MAKE_FILE=	Makefile
USE_TOOLS+=	pkg-config gmake

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Replace hardcoded paths
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths=		-e 's,"/usr/local,"${PREFIX},g'

#pre_install:
#	${CP} ../meka ${DESTDIR}${PREFIX}bin


#.include "../../devel/nasm/buil
DEPENDS+=	nasm>=2.0:../../devel/nasm

#.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../wip/allegro52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
