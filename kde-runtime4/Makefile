# $NetBSD: Makefile,v 1.64 2016/04/22 08:04:23 jperkin Exp $

DISTNAME=	kde-runtime-17.08.3
PKGNAME=	${DISTNAME:S/-1/4-1/}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Runtime requirements for the KDE integrated X11 desktop
MASTER_SITES=	${MASTER_SITE_KDE:=applications/17.08.3/src/}

.include "../../meta-pkgs/kde4/Makefile.kde4"

# BUILD_MAKE_FLAGS+= VERBOSE=1
CMAKE_CONFIGURE_ARGS+=	-DWITH_LibSSH:BOOL=OFF
.include "../../mk/bsd.prefs.mk"
CMAKE_CONFIGURE_ARGS+=	-DLIBLZMA_INCLUDE_DIR:PATH=${BUILDLINK_PREFIX.xz}/include
.if ${OPSYS} == "Darwin"
CMAKE_CONFIGURE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.dylib
.else
CMAKE_CONFIGURE_ARGS+=	-DLIBLZMA_LIBRARY:FILEPATH=${BUILDLINK_PREFIX.xz}/lib/liblzma.so
.endif

CMAKE_CONFIGURE_ARGS+=	-DWITH_QNtrack=OFF
CMAKE_CONFIGURE_ARGS+=	-DWITH_NepomukCore=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_khelpcenter=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_kglobalaccel=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_kuiserver=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_drkonqi=OFF
CMAKE_CONFIGURE_ARGS+=	-DBUILD_doc=OFF

#DEPENDS+=	htdig>=3.2.0:../../www/htdig
DEPENDS+=	oxygen-icons-[0-9]*:../../graphics/oxygen-icons

USE_TOOLS+=	gmake

CFLAGS.SunOS+=	-DPORTMAP
LDFLAGS.SunOS+=	-lsocket -lnsl

.include "options.mk"

# Some files are conditional on 'md5sum' or 'md5' being present.
PLIST_VARS+=	md5
.for dir in ${PATH:C/\:/ /g}
.  if exists(${dir}/md5sum) || exists(${dir}/md5)
PLIST.md5=	yes
.  endif
.endfor

PLIST_VARS+=	polkit x11
.if ${OPSYS} != "Darwin"
PLIST.polkit=	yes
PLIST.x11=	yes
.endif

#SUBST_CLASSES+=	htdig
#SUBST_STAGE.htdig=	post-patch
#SUBST_MESSAGE.htdig=	Fix htdig paths.
#SUBST_FILES.htdig=	khelpcenter/searchhandlers/khc_htsearch.pl
#SUBST_SED.htdig=	-e s:/srv/www/cgi-bin:${PREFIX}/libexec/cgi-bin:

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	kioslave/info/kde-info2html.conf
SUBST_SED.paths=	-e 's,@LOCALBASE@,${PREFIX},g'
SUBST_STAGE.paths=	post-patch

REPLACE_PERL+= \
	khelpcenter/searchhandlers/khc_docbookdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htdig.pl.cmake \
	khelpcenter/searchhandlers/khc_htsearch.pl \
	khelpcenter/searchhandlers/khc_mansearch.pl \
	kioslave/info/kde-info2html

CONF_FILES+=	${PREFIX}/share/examples/kde-runtime4/kde-information.menu \
		${PKG_SYSCONFDIR}/xdg/menus/kde-information.menu
CONF_FILES+=	${PREFIX}/share/examples/kde4-dbus/org.kde.kcontrol.kcmremotewidgets.conf \
		${PKG_SYSCONFDIR}/dbus-1/system.d/org.kde.kcontrol.kcmremotewidgets.conf

BUILDLINK_DEPMETHOD.qt4-tools=	full

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

.include "../../meta-pkgs/kde4/kde4.mk"

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
#.include "../../lang/python/application.mk"
# not the libssh the package wants
#.include "../../security/libssh/buildlink3.mk"
.include "../../security/gpgme/buildlink3.mk"
.include "../../security/qca2/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
BUILDLINK_ABI_DEPENDS.attica?=	attica>=0.1.4
.include "../../misc/attica/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../net/openslp/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
