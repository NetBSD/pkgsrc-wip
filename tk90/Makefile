# $NetBSD: Makefile,v 1.1 2025/03/08 11:46:37 scole Exp $

DISTNAME=	tk${TK_VERSION}-src
PKGNAME=	tk-${TK_VERSION}
CATEGORIES=	x11 lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tcl/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.tcl.tk/
COMMENT=	Graphical toolkit for TCL
LICENSE=	2-clause-bsd

# xxx
#.include "../../x11/tk/Makefile.version"
.include "../../x11/tk90/Makefile.version"

WRKSRC=			${WRKDIR}/tk${TK_VERSION}

USE_GCC_RUNTIME=	yes

GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		unix
BUILD_DIRS=		${CONFIGURE_DIRS}
CONFIGURE_ARGS+=	--with-tcl=${_CROSS_DESTDIR:U}${BUILDLINK_PREFIX.tcl}/lib

# xxx confusing arg to build tk zip file. man wish(1), zipfs(n)
CONFIGURE_ARGS+=	--disable-zipfs
CONFIGURE_ARGS+=	--enable-libcups=no

CONFIGURE_ENV+=		LIB_RUNTIME_DIR=${PREFIX}/lib
PKGCONFIG_OVERRIDE+=	unix/tk.pc.in
USE_TOOLS+=		ln

# xxx whether tests pass, fail, or even complete seems window manager
# dependent and/or if mouse pointer/focus changes.  ctwm was able to
# finish and passed almost all of the tests for me
TEST_TARGET=		test

CHECK_PORTABILITY_SKIP=	win/configure

.include "options.mk"

SUBST_CLASSES+=		tk-config
SUBST_STAGE.tk-config=	post-build
SUBST_FILES.tk-config=	unix/tkConfig.sh
SUBST_SED.tk-config+=	-e "s|${WRKSRC}/unix|${PREFIX}/lib|"
SUBST_SED.tk-config+=	-e "s|${WRKSRC}|${PREFIX}/include/tk|"

PLIST_SUBST+=		SONUM=${TK_SONUM}
PLIST_SUBST+=		BASEVER=${TK_BASEVER}
PLIST_SUBST+=		VERSION=${TK_VERSION}

post-install:
	cd ${WRKSRC}/unix && ${MAKE} \
		BIN_INSTALL_DIR=${DESTDIR}${PREFIX}/bin \
		LIB_INSTALL_DIR=${DESTDIR}${PREFIX}/lib \
		CONFIG_INSTALL_DIR=${DESTDIR}${PREFIX}/lib \
		SCRIPT_INSTALL_DIR=${DESTDIR}${PREFIX}/lib/tk${TK_BASEVER} \
		INCLUDE_INSTALL_DIR=${DESTDIR}${PREFIX}/include \
		PRIVATE_INCLUDE_DIR=${DESTDIR}${PREFIX}/include \
		MAN_INSTALL_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
		DEMO_INSTALL_DIR=${DESTDIR}${PREFIX}/lib/tk${TK_BASEVER}/demos \
		install install-binaries
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -fs wish${TK_BASEVER} wish

# xxx
#.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl90/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
