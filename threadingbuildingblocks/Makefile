# $NetBSD$

TBB_VERSION=	2017_20160916

DISTNAME=	tbb${TBB_VERSION}oss_src
PKGNAME=	threadingbuildingblocks-${TBB_VERSION:S/_/./}
CATEGORIES=	devel
MASTER_SITES=	https://www.threadingbuildingblocks.org/sites/default/files/software_releases/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.threadingbuildingblocks.org/sites/default/files/software_releases/source/
COMMENT=	Intel Threading Building Block
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/tbb${TBB_VERSION}oss
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake pax bash

GCC_REQD+=	5.3 # c++11

BUILD_TARGET=	# empty, all runs tests and it take a lot of time
MAKE_FLAGS+=	stdver=c++11

INSTALLATION_DIRS+=	include/tbb lib

TEST_TARGET=	test

SUBST_CLASSES+=		bash
SUBST_STAGE.bash=	pre-build
SUBST_FILES.bash=	build/FreeBSD.inc
SUBST_FILES.bash+=	build/AIX.inc
SUBST_FILES.bash+=	build/mic.offload.inc
SUBST_FILES.bash+=	build/SunOS.inc
SUBST_FILES.bash+=	build/macos.inc
SUBST_FILES.bash+=	build/linux.inc
SUBST_FILES.bash+=	build/netbsd.inc
SUBST_MESSAGE.bash=	Run bash script with bash.
SUBST_SED.bash=		-e "s|TEST_LAUNCHER=sh|TEST_LAUNCHER=${BASH}|1"

do-install:
.for file in libtbb.so.2 libtbbmalloc.so.2 libtbbmalloc_proxy.so.2
	cd ${WRKSRC}/build/netbsd*release/ && \
		${INSTALL_LIB} ${file} ${DESTDIR}${PREFIX}/lib
.endfor
	cd ${WRKSRC}/include && ${PAX} -rw . ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
