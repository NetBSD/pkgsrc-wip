# $NetBSD: Makefile,v 1.51 2018/12/10 14:59:50 leot Exp $

.include "../../wip/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

USE_TOOLS+=		pkg-config

USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DSWIPL_ARCH=${MACHINE_GNU_PLATFORM}
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=ON
CMAKE_ARGS+=		-DINSTALL_PACKAGES=OFF
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=OFF

# Part of swi-prolog-lite
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BASIC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_SSL=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TERM=OFF

# Part of swi-prolog-packages
CMAKE_ARGS+=		-DSWIPL_PACKAGES_X=OFF

SWIPL_PACKAGES_COMPONENTS+=	Java_interface

.include "../../mk/bsd.prefs.mk"

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

TEST_TARGET=	check

do-install:
.for component in ${SWIPL_PACKAGES_COMPONENTS}
	cd ${WRKSRC}/build &&						\
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}			\
		${CMAKE} -DCMAKE_INSTALL_COMPONENT=${component:Q}	\
			-P cmake_install.cmake
.endfor

.include "../../wip/swi-prolog-lite/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
