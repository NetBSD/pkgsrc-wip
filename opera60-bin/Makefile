# $NetBSD $

DISTNAME=		Opera_${OPERA_PKG_VERSION}.${OPERA_PKG_BUILD}_${OPERA_ARCH}
PKGNAME=		opera-${OPERA_PKG_VERSION:S/u/pl/}
CATEGORIES=		www
MASTER_SITES+=		${MASTER_SITE_OPERA:=${OPERA_DIR}/}
EXTRACT_SUFX=		.deb

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.opera.com/
COMMENT=		Standards-compliant graphical Web browser
LICENSE=		opera-1200-license #FIXME: new license, opera-2014

USE_TOOLS+=		tar gzip pax

EMUL_PLATFORMS=		freebsd-i386 freebsd-x86_64 \
			linux-i386 linux-x86_64

.include "../../mk/bsd.prefs.mk"

MASTER_SITE_OPERA+=	https://download1.operacdn.com/pub/opera/desktop/ \
			https://download2.operacdn.com/pub/opera/desktop/ \
			https://download3.operacdn.com/pub/opera/desktop/ \
			https://download4.operacdn.com/pub/opera/desktop/

USE_LANGUAGES=		# empty
NO_BUILD=		yes

OPERA_PKG_BUILD=	3255.95
OPERA_PKG_VERSION=	60.0
OPERA_PKG_VERSION_DIR=	${OPERA_PKG_VERSION}.${OPERA_PKG_BUILD}

PLIST_VARS+=		ia32w linux

# (NEEDED) shared libraries. Sorted by DONE and TODO
# DONE: libcurl.so.4 libnss3.so libnspr4.so libcups.so.2 libX11.so.6
# DONE: libnssutil3.so libglib-2.0.so.0 libexpat.so.1 libdbus-1.so.3
# DONE: libXext.so.6 libXrandr.so.2 libXss.so.1 libXtst.so.6 libXi.so.6
# DONE: libXdamage.so.1 libXfixes.so.3 libXcursor.so.1 libXrender.so.1
# DONE: libX11.so.1 libxcb.so.1 libXcomposite.so.1 libasound.so.2
# DONE: libc.so.6 libgcc_s.so.1
# TODO: libffmpeg.so libdl.so.2 libpthread.so.0
# 	librt.so.1 libgobject-2.0.so.0
# 	libsmime3.so libpangocairo-1.0.so.0
# 	libpango-1.0.so.0 libcairo.so.2 libgio-2.0.so.0
# 	libgdk_pixbuf-2.0.so.0
# 	libuuid.so.1
# 	libatk-1.0.so.0 libatk-bridge-2.0.so.0
# 	libatspi.so.0 libm.so.6 libgtk-3.so.0 libgdk-3.so.0
# 	ld-linux-x86-64.so.2


.if ${EMUL_OPSYS} == "linux"
EMUL_MODULES.linux=	base x11 fontconfig curl nss dbus cups nspr glib2 expat alsa
EMUL_REQD=		suse>=11.3
OPERA_ARCH.x86_64=	amd64
OPERA_OPSYS_SUBDIR=	linux
.  if !defined(EMUL_IS_NATIVE) && ${OPSYS} == "NetBSD"
TOOLS_CREATE+=		md5
TOOLS_SCRIPT.md5=	/usr/bin/md5 -n "$$2" | { read sum file; echo $$sum; }
.  endif
.  if ${EMUL_ARCH} == "x86_64"
PLIST.ia32w=		yes
.  endif
PLIST.linux=		yes

.elif ${EMUL_OPSYS} == "freebsd"
OPERA_ARCH.x86_64=		amd64
OPERA_OPSYS_SUBDIR=		unix
# XXX: TBD
#.  if defined(EMUL_IS_NATIVE)
#DEPENDS+=			{gtk2+-[0-9]*,kdelibs4-[0-9]*}:../../x11/gtk2
#CHECK_SHLIBS_SUPPORTED=	no
#.  endif
.endif
OPERA_ARCH=			${OPERA_ARCH.${EMUL_ARCH}:U${EMUL_ARCH}}
OPERA_DIR=			${OPERA_PKG_VERSION_DIR}/${OPERA_OPSYS_SUBDIR}

MANCOMPRESSED=		yes

SUBST_CLASSES+=		plugin
SUBST_STAGE.plugin=	post-install
SUBST_FILES.plugin=	${DESTDIR}${PREFIX}/share/opera/defaults/pluginpath.ini
SUBST_SED.plugin=	-e 's,/usr/local/,${PREFIX}/,g'

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin share/applications share/pixmaps

do-extract: ${WRKDIR}
	${RUN} cd ${WRKDIR} && ${AR} x ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} data.tar.xz
	cd ${WRKSRC} && ${TAR} -xzpf data.tar.xz
	chmod go-w ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/usr/share/applications/opera.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/usr/share/pixmaps/opera.xpm ${DESTDIR}${PREFIX}/share/pixmaps
	cd ${WRKSRC}/usr/lib/x86_64-linux-gnu && pax -rw -pm * ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}
	${LN} -f ${DESTDIR}${PREFIX}/${PKGNAME_NOREV}/opera/opera ${DESTDIR}${PREFIX}/bin/opera

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
