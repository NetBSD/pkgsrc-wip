# $NetBSD$

FLNEWS_VERSION=	0.18pre1

DISTNAME=	flnews-${FLNEWS_VERSION}
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/flnews/src/
MASTER_SITES+=	http://www.ybtra.de/flnews-mirror/src/
MASTER_SITES+=	http://www.southcity.de/flnews/src/
EXTRACT_SUFX=	.tar.bz2
#EXTRACT_USING=	bsdtar

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	http://micha.freeshell.org/flnews/
COMMENT=	Fast and lightweight USENET newsreader with GUI
LICENSE=	modified-bsd AND 2-clause-bsd AND unicode

USE_LANGUAGES=	c c++

TEST_TARGET=	test

# Bug report contact address used for GUI
FLNEWS_MAINTAINER=	${MAINTAINER}

.include "options.mk"

post-extract:
	${CP} ${FILESDIR}/CONFIG ${WRKSRC}

# Prepare CONFIG file
SUBST_CLASSES+=			edit-config
SUBST_STAGE.edit-config=	pre-configure
SUBST_MESSAGE.edit-config=	Preparing CONFIG file ...
SUBST_FILES.edit-config=	CONFIG
SUBST_SED.edit-config=		-e 's,@VERSION@,${FLNEWS_VERSION},g'
SUBST_VARS.edit-config=		PREFIX
SUBST_SED.edit-config+=		-e 's,@MAINT@,${FLNEWS_MAINTAINER},g'
SUBST_SED.edit-config+=		-e 's,@IP6@,${FLNEWS_OPT_DISABLE_IP6},g'
SUBST_SED.edit-config+=		-e 's,@NLS@,${FLNEWS_OPT_DISABLE_NLS},g'
SUBST_SED.edit-config+=		-e 's,@XDBE@,${FLNEWS_OPT_DISABLE_XDBE},g'
SUBST_SED.edit-config+=		-e 's,@MAN_PATH@,${PREFIX}/${PKGMANDIR},g'
# NetBSD reports X/Open XSI extension as not available using the POSIX
# sysconf(_SC_XOPEN_VERSION) call, but has a sufficient implementation
# => Force using it
.if ${OPSYS} == "NetBSD"
SUBST_SED.edit-config+=		-e 's,@FORCE_XSI@,1,g'
.else
SUBST_SED.edit-config+=		-e 's,@FORCE_XSI@,0,g'
.endif
# NetBSD reports IPv6 as not available using the POSIX sysconf(_SC_IPV6)
# call, but has a sufficient implementation
# => Force using it if inet6 option of pkgsrc package is selected
.if ${OPSYS} == "NetBSD" && ${FLNEWS_OPT_DISABLE_IP6} == 0
SUBST_SED.edit-config+=		-e 's,@FORCE_IP6@,1,g'
.else
SUBST_SED.edit-config+=		-e 's,@FORCE_IP6@,0,g'
.endif
# Old SunPro compilers cannot create dependencies with the "-M" option
# => Use makedepend instead for all SunPro compilers
.if ${OPSYS} == "SunOS" && ${PKGSRC_COMPILER:Msunpro}
SUBST_SED.edit-config+=		-e 's,@DEP_MD@,,g'
SUBST_SED.edit-config+=		-e 's,@DEP_COMP@,\#,g'
.else
SUBST_SED.edit-config+=		-e 's,@DEP_MD@,\#,g'
SUBST_SED.edit-config+=		-e 's,@DEP_COMP@,,g'
.endif

INSTALLATION_DIRS+=		share/applications
INSTALLATION_DIRS+=		share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=		share/icons/hicolor/64x64/apps

pre-configure:
	${MKDIR} ${WRKDIR}/desktop
	${CP} ${FILESDIR}/flnews.desktop ${WRKDIR}/desktop
	${MKDIR} ${WRKDIR}/desktop/48x48
	${CP} ${FILESDIR}/48x48/flnews.png ${WRKDIR}/desktop/48x48
	${MKDIR} ${WRKDIR}/desktop/64x64
	${CP} ${FILESDIR}/64x64/flnews.png ${WRKDIR}/desktop/64x64

do-configure:
	cd ${WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} config

post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop/flnews.desktop \
		${DESTDIR}${PREFIX}/share/applications/flnews.desktop
	${INSTALL_DATA} ${WRKDIR}/desktop/48x48/flnews.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/flnews.png
	${INSTALL_DATA} ${WRKDIR}/desktop/64x64/flnews.png \
		${DESTDIR}${PREFIX}/share/icons/hicolor/64x64/apps/flnews.png

.if ${OPSYS} == "SunOS" && ${PKGSRC_COMPILER:Msunpro}
BUILD_DEPENDS+=			makedepend-[0-9]*:../../devel/makedepend
.endif

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
# OpenSSL 1.1 API is required for signature algorithm negotiation
# OpenSSL 1.1 API is required for TLSv1.2 FFDHE group check
# At least OpenSSL 1.1.1 is required for TLSv1.3
# OpenSSL 3 API is required for FFDHE group negotiation
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.0
.include "../../security/openssl/buildlink3.mk"
# Quoted from comment:
# | This Makefile fragment is intended to be included by packages that install
# | desktop entries.
# There is a desktop entry, but no MIME types are associated with this program.
# Is this nevertheless required?
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
# FLTK must be compiled with multithreading support
# FLTK version 1.4 is supported (should be compiled with pango support)
#.include "../../x11/fltk13/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
