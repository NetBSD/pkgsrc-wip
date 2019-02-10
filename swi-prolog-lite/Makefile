# $NetBSD: Makefile,v 1.28 2018/12/10 14:59:50 leot Exp $

.include "Makefile.common"

PKGNAME=		swi-prolog-lite-${SWIPLVERS}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		ISO/Edinburgh-style Prolog compiler

CMAKE_ARGS+=		-DSWIPL_ARCH=${MACHINE_GNU_PLATFORM}
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BASIC=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ARCHIVE=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_SSL=ON
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TERM=ON
CMAKE_ARGS+=		-DINSTALL_DOCUMENTATION=ON

# XXX: Explicitly disable all not wanted packages to avoid possible build
# XXX: failures. For a complete list please see:
# XXX:  ${WRKSRC}/cmake/PackageSelection.cmake
CMAKE_ARGS+=		-DSWIPL_PACKAGES_ODBC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_BDB=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_PCRE=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_YAML=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_JAVA=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_TIPC=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_QT=OFF
CMAKE_ARGS+=		-DSWIPL_PACKAGES_X=OFF

#CONFIGURE_ENV+=		PL=swi-prolog
#CONFIGURE_ENV+=		PLARCH=${MACHINE_GNU_PLATFORM}	# make PLIST consistent
#USE_TOOLS+=		gmake bash:run
USE_TOOLS+=		bash:run

USE_LANGUAGES=		c c++

.include "../../mk/bsd.prefs.mk"

.if !empty(LP64PLATFORMS:@.PLAT.@${MACHINE_PLATFORM:M${.PLAT.}}@) || \
    (defined(ABI) && ${ABI} == "64")
PLIST_SUBST+=		BITS=64
.else
PLIST_SUBST+=		BITS=32
.endif

REPLACE_INTERPRETER+=	swipl
REPLACE.swipl.old=	/usr/bin/swipl
REPLACE.swipl.new=	${PREFIX}/bin/swi-prolog
REPLACE_FILES.swipl+=	library/dialect/sicstus/swipl-lfr.pl

# XXX: editline bindings seems limited and does not support completion, remove
# XXX: them in order to always use readline.pl.
post-install:
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/lib/${MACHINE_GNU_PLATFORM}/libedit4pl.so || ${TRUE}
	${RM} ${DESTDIR}${PREFIX}/lib/swipl/library/editline.pl || ${TRUE}

TEST_TARGET=		check

.include "../../archivers/libarchive/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/ossp-uuid/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
