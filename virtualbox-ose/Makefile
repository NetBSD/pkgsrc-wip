# $NetBSD$
DISTNAME=virtualbox-ose-${DISTVERSION}

# FreeBSD ports in emulator category
CATEGORIES=	devel
DISTVERSION=	4.3.30
MASTER_SITES=	http://download.virtualbox.org/virtualbox/${DISTVERSION}/ \
	http://tmp.chruetertee.ch/ \
	http://disasterarea.chruetertee.ch/ \
	http://download.virtualbox.org/virtualbox/${VBOX_GUEST_VER}/:guestadditions
DISTFILES= VirtualBox-${DISTVERSION}${EXTRACT_SUFX} ${GADISTFILES}
EXTRACT_ONLY= VirtualBox-${DISTVERSION}${EXTRACT_SUFX}
EXTRACT_SUFX=	.tar.bz2

# To try, disable following line, thanks
BROKEN=		Package is not completed yet, sorry.

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	General-purpose full virtualizer for x86 hardware
LICENSE=	gnu-gpl-v2

DEPENDS+=	cdrtools-[0-9]*:../../sysutils/cdrtools

BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm
BUILD_DEPENDS+=	kbuild-[0-9]*:../../wip/kbuild

USE_TOOLS+=	gtar pkg-config gmake

WRKSRC=		${WRKDIR}/VirtualBox-${DISTVERSION}
ONLY_FOR_PLATFORM+= *-*-i386
ONLY_FOR_PLATFORM+= *-*-x86_64

CONFIGURE_ARGS=	# empty
CONFIGURE_ARGS+= --disable-java --passive-mesa
CONFIGURE_ARGS+= --with-gcc="${CC}" --with-g++="${CXX}"
GNU_CONFIGURE=	yes
USE_LANGUAGES+=	c c++

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix+=	configure
SUBST_FILES.prefix+=	src/VBox/Additions/x11/Installer/98vboxadd-xclient
SUBST_FILES.prefix+=	src/VBox/Installer/freebsd/VBox.sh
SUBST_FILES.prefix+=	src/VBox/Additions/x11/Installer/vboxclient.desktop
SUBST_FILES.prefix+=	kBuild/header.kmk
SUBST_FILES.prefix+=	Config.kmk

SUBST_MESSAGE.prefix+=	Configure prefix to ${PREFIX}
SUBST_STAGE.prefix+=	pre-configure
SUBST_VARS.prefix+=	PREFIX X11BASE PYVERSSUFFIX

KMK_CONFIG=	VBOX_LIBPATH_X11=${X11BASE}/lib
KMK_CONFIG+=	VBOX_FREEBSD_SRC=/usr/src/sys
KMK_CONFIG+=	KBUILD_PATH=${WRKSRC}/kBuild
KMK_FLAGS=	-j1

post-patch:
	@${ECHO} 'VBOX_PATH_APP_PRIVATE_ARCH = ${VBOX_DIR}' > \
	${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_SHARED_LIBS = ${VBOX_DIR}' >> \
	${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_RUNPATH = ${VBOX_DIR}' >> \
	${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_PRIVATE = ${DATADIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_PATH_APP_DOCS = ${DOCSDIR}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_INSTALLER = 1' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_VBOXDRV =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_TESTCASES =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_INCS = ${PREFIX}/include/libpng' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'SDK_VBOX_LIBPNG_LIBS = png' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_DRAG_AND_DROP = ${VBOX_WITH_QT4}' >> ${WRKSRC}/LocalConfig.kmk
	@${ECHO} 'VBOX_WITH_X11_ADDITIONS =' >> ${WRKSRC}/LocalConfig.kmk
	@${MKDIR} ${WRKSRC}/src/VBox/Installer/netbsd
	@${CP}    ${FILESDIR}/src-VBox-Installer-netbsd-Makefile.kmk ${WRKSRC}/src/VBox/Installer/netbsd/Makefile.kmk

do-build:
	cd ${WRKSRC}/ && \
	${SH} -c . kBuild/env.sh && ${KMK_CONFIG} ${PREFIX}/bin/kmk ${KMK_FLAGS}
	.if ${PORT_OPTIONS:MPYTHON}
	${PYTHON_CMD} -mcompileall ${KMK_BUILDDIR}/bin/sdk/bindings/xpcom/python/xpcom
	.endif

.include	"../../graphics/png/buildlink3.mk"
.include	"../../multimedia/libvpx/buildlink3.mk"
.include	"../../www/curl/buildlink3.mk"
.include	"../../graphics/png/buildlink3.mk"
.include	"../../textproc/libxslt/buildlink3.mk"
.include	"../../devel/SDL/buildlink3.mk"
.include	"../../devel/glib2/buildlink3.mk"
.include	"../../x11/libXext/buildlink3.mk"
.include	"../../x11/qt4-libs/buildlink3.mk"
.include	"../../lang/python/pyversion.mk"
.include	"../../lang/python/application.mk"

.include	"../../mk/bsd.pkg.mk"
