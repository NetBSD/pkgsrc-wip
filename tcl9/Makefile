# $NetBSD$

TCL_VERSION=	9.0.1
DISTNAME=	tcl${TCL_VERSION}-src
PKGNAME=	tcl-${TCL_VERSION}
CATEGORIES=	lang
MASTER_SITES=	http://prdownloads.sourceforge.net/tcl/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prdownloads.sourceforge.net/tcl/
COMMENT=	Tool Command Language, a dynamic language
LICENSE=	2-clause-bsd

WRKSRC=		${WRKDIR}/tcl${TCL_VERSION}

USE_GCC_RUNTIME=	yes

GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
INSTALL_TARGET=		install

CONFIGURE_ARGS+=	--without-tzdata

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	compat/zlib/contrib/minizip/minizip.pc.in
PKGCONFIG_OVERRIDE+=	compat/zlib/zlib.pc.in
PKGCONFIG_OVERRIDE+=	libtommath/libtommath.pc.in
PKGCONFIG_OVERRIDE+=	unix/tcl.pc.in

CHECK_PORTABILITY_SKIP=	win/configure

TEST_TARGET=		test

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no
CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyaddr_r=no

SUBST_CLASSES+=		tcl-config
SUBST_STAGE.tcl-config=	post-build
SUBST_FILES.tcl-config=	unix/tclConfig.sh
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tcl-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tcl|"

PLIST_SUBST+=		SONUM=${TCL_SONUM}
PLIST_SUBST+=		BASEVER=${TCL_BASEVER}
PLIST_SUBST+=		ITCL_VERSION=${ITCL_VERSION}
PLIST_SUBST+=		SQLITE3_VERSION=${SQLITE3_VERSION}
PLIST_SUBST+=		TDBC_VERSION=${TDBC_VERSION}
PLIST_SUBST+=		THREAD_VERSION=${THREAD_VERSION}

CONFIGURE_ARGS+=	--with-system-sqlite
CONFIGURE_ARGS+=        --enable-threads
##SUBST_CLASSES+=		sqllink
##SUBST_STAGE.sqllink=	pre-configure
##SUBST_FILES.sqllink=	pkgs/sqlite${SQLITE3_VERSION}/configure
##SUBST_SED.sqllink=	-e "/LIBS=/s|-lsqlite3|-L${BUILDLINK_PREFIX.sqlite3}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.sqlite3}/lib -lsqlite3|g"

# install-sh requires $SHELL is an extremely close match to /bin/sh

MAKE_ENV+=		SHELL=${SH:Q}

post-install:
	cd ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3 && mv Thread.3 Tcl_Thread.3


.include "../../mk/bsd.pkg.mk"
BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=${SQLITE3_VERSION}
.include "../../mk/pthread.buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
