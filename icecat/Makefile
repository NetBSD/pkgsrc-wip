# $NetBSD: Makefile,v 1.5 2009/03/24 13:15:39 yhardy Exp $

MOZILLA=		icecat
MOZILLA_BIN=		icecat-bin
COMMENT=		Lightweight gecko-based web browser

PKG_DESTDIR_SUPPORT=	user-destdir

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

INSTALLATION_DIRS=	lib/pkgconfig share/applications share/pixmaps

CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.4

# Pull in standard firefox build framework, and override some things below.
# This include must appear first, to ensure that USE_LANGUAGES is set
# correctly before mk/compiler.mk may be loaded.
.include "../../www/firefox/Makefile-firefox.common"

MAINTAINER=		pkgsrc-users@NetBSD.org
MOZ_VER=		3.0.7
MOZILLA_BIN=		icecat-bin

DISTNAME=		icecat-${MOZ_VER}-g1
MASTER_SITES=		http://ftp.gnu.org/gnu/gnuzilla/${MOZ_VER}-g1/
MASTER_SITES+=		http://www.gnu.org/software/gnuzilla/
EXTRACT_SUFX=		.tar.bz2
HOMEPAGE=		http://www.gnu.org/software/gnuzilla/
WRKSRC=			${WRKDIR}/${DISTNAME}

DISTFILES=      	${DISTNAME}${EXTRACT_SUFX}

XPTCFILES:=		${XPTCFILES:C,^,../../firefox3/files/,}
DESCR_SRC=		${.CURDIR}/../../wip/icecat/DESCR
DISTINFO_FILE=		${.CURDIR}/../../wip/icecat/distinfo
PATCHDIR=		${.CURDIR}/../../www/firefox3/patches

CONFLICTS=		firefox3

#PLIST_SUBST+=		MOZILLA=${MOZILLA:Q}
#PLIST_SUBST+=		MOZILLA_BIN=${MOZILLA_BIN:Q}
#FILES_SUBST+=		MOZILLA=${MOZILLA:Q}
#FILES_SUBST+=		MOZILLA_BIN=${MOZILLA_BIN:Q}

.PHONY: copy-pkgconfig
post-extract: copy-pkgconfig
copy-pkgconfig:
	cp ${.CURDIR}/../../wip/icecat/files/*.pc ${WRKSRC:Q}/build/unix

SUBST_CLASSES+=		fix-pc
SUBST_STAGE.fix-pc=	pre-configure
SUBST_MESSAGE.fix-pc=	Substituting prefix in pkg-config files.
SUBST_FILES.fix-pc+=	build/unix/*.pc
SUBST_SED.fix-pc=	-e 's,@PREFIX@,${PREFIX},g'

# We don't have libxcb yet
SUBST_CLASSES+=		no-xcb
SUBST_STAGE.no-xcb=	pre-patch
SUBST_MESSAGE.no-xcb=	Removing dependency on libxcb.
SUBST_FILES.no-xcb+=	configure.in
SUBST_SED.no-xcb=	-e 's,PKG_CHECK_MODULES(XCB,\#PKG_CHECK_MODULES(XCB,g'

# Need this to be able to reuse existing firefox pkgsrc infrastructure
.PHONY: create-dummy-c-sdk
pre-configure: create-dummy-c-sdk
create-dummy-c-sdk:
	mkdir -p ${WRKSRC:Q}/directory/c-sdk
	touch ${WRKSRC:Q}/directory/c-sdk/configure.in

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

# Link browser.xpt
.PHONY: stage-package
post-build: stage-package
stage-package:
	cd ${WRKSRC}/browser/installer && \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} stage-package
	cp ${WRKSRC}/dist/icecat/components/browser.xpt \
	   ${WRKSRC}/dist/bin/components/browser.xpt

.if !empty(PKG_OPTIONS:Mmozilla-jemalloc)
PLIST_SUBST+=		JEMALLOC=
SCRIPTS_ENV+=		JEMALLOC=
.PHONY: install-libjemalloc
post-install: install-libjemalloc
install-libjemalloc:
	${INSTALL_LIB} ${WRKSRC}/dist/lib/libjemalloc.${SO_SUFFIX} \
	  ${DESTDIR}${PREFIX}/lib/${MOZILLA}/libjemalloc.${SO_SUFFIX}
.else
PLIST_SUBST+=		JEMALLOC="@comment "
SCRIPTS_ENV+=		JEMALLOC="@comment "
.endif

MOZILLA_NAME=	IceCat 3
MOZILLA_ICON=	${WRKSRC}/browser/branding/unofficial/content/default.png

.PHONY: preinstall-icon
pre-install: preinstall-icon
preinstall-icon:
	${INSTALL_DATA_DIR} ${WRKSRC}/dist/bin/chrome/icons/default
	${INSTALL_DATA} ${MOZILLA_ICON}				\
	    ${WRKSRC}/dist/bin/chrome/icons/default/default.png

.PHONY: install-desktop
post-install: install-desktop
install-desktop:
	${SED}							\
		-e 's|@MOZILLA@|${MOZILLA}|g'			\
		-e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'		\
		-e 's|@FIREFOX_ICON@|${MOZILLA}.png|g'		\
		<${.CURDIR}/../../www/firefox3/files/firefox3.desktop.in \
		>${WRKDIR}/${MOZILLA}.desktop
	${INSTALL_DATA} ${WRKDIR}/${MOZILLA}.desktop		\
	    ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}				\
	    ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

INSTALLATION_DIRS+=	lib/${MOZILLA}/modules

# configure says: "Can't use system PNG because it doesn't have APNG support"
CONFIGURE_ARGS+=	--without-system-png
# Override www/firefox's idea of toolkit
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
# Is dbus support useful for anything?
CONFIGURE_ARGS+=	--disable-dbus
# Avoids needing curl on Linux
CONFIGURE_ARGS+=	--disable-crashreporter

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

CONFIGURE_ARGS+=	--enable-system-sqlite
BUILDLINK_API_DEPENDS.sqlite3+= sqlite3>=3.5.9
.include "../../databases/sqlite3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
