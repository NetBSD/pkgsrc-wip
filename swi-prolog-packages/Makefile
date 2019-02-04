# $NetBSD: Makefile,v 1.51 2018/12/10 14:59:50 leot Exp $

.include "../../wip/swi-prolog-lite/Makefile.common"

PKGNAME=		swi-prolog-packages-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Packages for SWI Prolog

USE_TOOLS+=		pkg-config
#MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++

CMAKE_ARGS+=		-DSWIPL_ARCH=${MACHINE_GNU_PLATFORM}
CMAKE_ARGS+=		-DSWIPL_PACKAGES=ON
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=ON

# XXX: Explicitly disable all not wanted packages to avoid possible build
# XXX: failures. For a complete list please see:
# XXX:  ${WRKSRC}/cmake/PackageSelection.cmake
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ODBC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BDB=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_PCRE=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_YAML=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TIPC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_QT=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=OFF

SWIPL_PACKAGES_COMPONENTS+=	Core_packages
SWIPL_PACKAGES_COMPONENTS+=	Archive_interface
SWIPL_PACKAGES_COMPONENTS+=	Commandline_editors
SWIPL_PACKAGES_COMPONENTS+=	OpenSSL_interface
SWIPL_PACKAGES_COMPONENTS+=	Graphics_subsystem
SWIPL_PACKAGES_COMPONENTS+=	Documentation

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
BUILD_DEPENDS+=		modular-xorg-server-[0-9]*:../../x11/modular-xorg-server
.endif

#CONFIGURE_ENV+=		PL=swi-prolog
#CONFIGURE_ENV+=		PLARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
#CONFIGURE_ARGS+=	--without-jpl

# XXX: check if still needed
#CONFIGURE_DIRS+=	. packages
#BUILD_DIRS+=		packages
#INSTALL_DIRS+=		packages

#INSTALLATION_DIRS=	bin lib/swi-prolog-${PKGVERSION_NOREV}/include ${PKGMANDIR}/man1

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

TEST_TARGET=	check

# XXX: check if still needed
#pre-configure:
#	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
#	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src
#
#post-configure:
#	${LN} -sf ${LOCALBASE}/bin/plld       ${WRKSRC}/src
#	${LN} -sf ${LOCALBASE}/bin/swi-prolog ${WRKSRC}/src
#	cd ${WRKSRC}/packages; \
#	${SETENV} \
#		CPP=${CPP:Q} \
#		${GMAKE} configure
#	mkdir ${WRKSRC}/include
#	${LN} -sf ${WRKSRC}/src/SWI-Prolog.h ${WRKSRC}/include
#	${LN} -sf ${WRKSRC}/src/os/SWI-Stream.h ${WRKSRC}/include
#
#pre-install: checkforx
#
## Based on misc/openoffice:
#DISPLAY?=	#empty, if unset
#checkforx:
#.if ${DISPLAY} == "" || ${DISPLAY_OK:!${X11BASE}/bin/xdpyinfo >/dev/null 2>&1 && ${ECHO} YES || ${ECHO} NO!} == "NO"
#.  if exists(${X11BASE}/bin/Xvfb)
#	-${X11BASE}/bin/Xvfb :2 & \
#	${ECHO} $$! >${WRKDIR}/.Xvfb.pid
#	${ECHO} checkforx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
#	sleep 5
#DISPLAY= :2
#.  else
#	@${ECHO} "Error: Environment variable DISPLAY must be set"
#	@${ECHO} "       and point to a connectible X server."
#	@${FALSE}
#.  endif  #Xvfb
#.endif  #DISPLAY
#
#MAKE_ENV+=		DISPLAY=${DISPLAY:Q}
#
## XXX: editline bindings seems limited and does not support completion, remove
## XXX: them in order to always use readline.pl.
#post-install: teardownx
#	${RM} ${DESTDIR}${PREFIX}/lib/swi-prolog-${PKGVERSION}/lib/${MACHINE_GNU_PLATFORM}/libedit4pl.so || ${TRUE}
#	${RM} ${DESTDIR}${PREFIX}/lib/swi-prolog-${PKGVERSION}/library/editline.pl || ${TRUE}
#	${RM} -f ${LOCALBASE}/lib/swi-prolog-${SWIPLVERS}/xpce-${XPCE_VERSION}/prolog/lib/.pwd
#	${INSTALL_DATA} ${WRKSRC}/packages/xpce/man/xpce-client.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpce-client.1
#	${INSTALL_DATA} ${WRKSRC}/packages/xpce/man/xpce.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xpce.1
#
#teardownx:
#	${ECHO} teardownx: Xvfb-PID: `${CAT} ${WRKDIR}/.Xvfb.pid`
#	sleep 5
#	-kill `${CAT} ${WRKDIR}/.Xvfb.pid`
#	${RM} -f ${WRKDIR}/.Xvfb.pid

do-install:
.for component in ${SWIPL_PACKAGES_COMPONENTS}
	cd ${WRKSRC}/build &&						\
	${PKGSRC_SETENV} ${INSTALL_ENV} ${MAKE_ENV}			\
		${CMAKE} -DCMAKE_INSTALL_COMPONENT=${component:Q}	\
			-P cmake_install.cmake
.endfor

# XXX: editline bindings seems limited and does not support completion, remove
# XXX: them in order to always use readline.pl.
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/lib/${MACHINE_GNU_PLATFORM}/libedit4pl.so || ${TRUE}
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/library/editline.pl || ${TRUE}

# I need this on FreeBSD, perhaps this depends on GCC behaviour:
CHECK_WRKREF_SKIP=	lib/swi-prolog-${SWIPLVERS}/xpce-${XPCE_VERSION}/lib/${MACHINE_GNU_PLATFORM}/pl2xpce.so


.include "../../archivers/libarchive/buildlink3.mk"
.include "../../wip/swi-prolog-lite/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
