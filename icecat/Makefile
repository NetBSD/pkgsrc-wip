# $NetBSD: Makefile,v 1.9 2009/09/11 14:01:18 yhardy Exp $
#

DISTNAME=	icecat-${ICECAT_VER}
ICECAT_VER=	3.5.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=gnuzilla/${ICECAT_VER}/}
#MASTER_SITES=	http://ftp.gnu.org/gnu/gnuzilla/${ICECAT_VER}-g1/
#MASTER_SITES+=	http://www.gnu.org/software/gnuzilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gnuzilla/
COMMENT=	GNU version of www/firefox

WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl gmake autoconf213
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

PRIVILEGED_STAGES=	clean

CONFIG_GUESS_OVERRIDE=	build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	js/src/build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	nsprpub/build/autoconf/config.guess
CONFIG_SUB_OVERRIDE=	build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	js/src/build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	nsprpub/build/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=browser
CONFIGURE_ARGS+=	--enable-libxul
CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads
CONFIGURE_ARGS+=	--disable-gnomeui --disable-javaxpcom
CONFIGURE_ARGS+=	--disable-dbus --disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg --enable-mathml
CONFIGURE_ARGS+=	--enable-system-cairo --enable-system-lcms
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib --with-system-bz2
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter

ALL_ENV+=		MOZILLA_PKG_NAME=icecat

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

MOZILLA=	icecat
MOZILLA_NAME=	IceCat 3
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/content/default.png

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC}/nsprpub && autoconf

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

.PHONY: install-desktop
post-install: install-desktop
install-desktop:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/pixmaps
	${SED}	-e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@ICECAT_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.if ${OPSYS} == "Linux"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
