# $NetBSD: Makefile,v 1.51 2018/12/10 14:59:50 leot Exp $

.include "../../wip/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

USE_TOOLS+=		pkg-config

CMAKE_ARGS+=		-DINSTALL_PACKAGES=ON
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=ON

# Part of swi-prolog-lite
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BASIC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_SSL=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TERM=OFF

# Part of swi-prolog-lite... ...but needed to build documentation.
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=ON

# Part of swi-prolog-jpl
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=OFF

SWIPL_PACKAGES_COMPONENTS+=	Graphics_subsystem

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

# I need this on FreeBSD, perhaps this depends on GCC behaviour:
CHECK_WRKREF_SKIP=	lib/swi-prolog-${SWIPLVERS}/xpce-${XPCE_VERSION}/lib/${MACHINE_GNU_PLATFORM}/pl2xpce.so


.include "../../wip/swi-prolog-lite/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
