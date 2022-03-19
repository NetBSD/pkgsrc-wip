# $NetBSD: Makefile,v 1.99 2021/11/01 21:41:59 wiz Exp $
#
# How to update this package:
#
# replace all patches with the one from the correspoding www/firefox${ESR_RELEASE}
# compare e.g. the output of
# diff -r -I NetBSD . ../../www/firefox91
# BUT keep:
# patch-.mozconfig (if still necessary)
# patch-browser_app_profile_000-tor-browser.js
# patch-toolkit_moz.configure (second chunk)
# patch-xpcom_io_TorFileUtils.cpp
# make the patches apply
#
# when packaged up, read MESSAGE and test by visiting https://check.torproject.org
# and https://panopticlick.eff.org

DISTNAME=	src-firefox-tor-browser-91.7.0esr-11.0-1-build4
PKGNAME=	tor-browser-11.0.9
CATEGORIES=	security www
MASTER_SITES=	https://dist.torproject.org/torbrowser/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	tor-browser-linux64-${PKGVERSION_NOREV}_en-US${EXTRACT_SUFX}
#DISTFILES+=	src-tor-launcher-0.2.32${EXTRACT_SUFX}
DISTFILES+=	nodejs-output-11.0.1.tgz
SITES.nodejs-output-11.0.1.tgz=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.torproject.org/projects/torbrowser.html.en
COMMENT=	Tor Browser based on Firefox
LICENSE=	mpl-1.1

# -------- BEFORE UPDATING THIS PACKAGE PLEASE READ & UNDERSTAND: -------
#
# This package works around a (stupid) build time dependency on nodejs
# (which is not available for all architectures and unnecessary for the
# real build). To do this, it places some additional burden on the
# maintainer.
#
# While working on the package, please make sure you have
#
#	FIREFOX_MAINTAINER=yes
#
# set in your build environment.
# When the package is ready for commit (but before commit), do:
#
#	make maintainer-files
#
# This will do another round (depending on state of your work dir at this
# moment) of one or two builds and generate a cache of all output that
# nodejs generates during a build.
#
# When this is done, just commit the results (they will be in the files/
# directory).
#
# -----------------------------------------------------------------------
UNLIMIT_RESOURCES+=	datasize virtualsize

WRKSRC=		${WRKDIR}/${DISTNAME:S/src-//}

MOZILLA_DIR=	# empty

DEPENDS+=	tor-[0-9]*:../../net/tor
DEPENDS+=	tor-browser-https-everywhere>=2020.5.20:../../security/tor-browser-https-everywhere
DEPENDS+=	tor-browser-noscript>=11.0.32:../../security/tor-browser-noscript

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--enable-tor-browser-data-outside-app-dir
CONFIGURE_ARGS+=	--with-tor-browser-version=${PKGVERSION_NOREV}
CFLAGS+=		-DTOR_BROWSER_DATA_IN_HOME_DIR=1
CFLAGS+=		-DTOR_BROWSER_DATA_OUTSIDE_APP_DIR=1

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib
LDFLAGS.DragonFly+=	-lplc4 -lnspr4
LDFLAGS.FreeBSD+=	-lplc4 -lnspr4
LDFLAGS.Linux+=		-lnspr4
LDFLAGS.SunOS+=		-lm

ALL_ENV+=		MOZ_APP_NAME=${PKGBASE}

# Avoid ld "invalid section index" errors.
BUILDLINK_TRANSFORM.SunOS+=	rm:-fdata-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-ffunction-sections
BUILDLINK_TRANSFORM.SunOS+=	rm:-pie

# Workaround for https://bugs.llvm.org/show_bug.cgi?id=46366
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fexperimental-new-pass-manager

SUBST_CLASSES+=		fonts
SUBST_STAGE.fonts=	pre-configure
SUBST_FILES.fonts+=	tor-browser_en-US/Browser/TorBrowser/Data/fontconfig/fonts.conf
SUBST_SED.fonts+=	-e 's,<dir>fonts</dir>,<dir>${PREFIX}/lib/tor-browser/browser/fonts</dir>,'
SUBST_MESSAGE.fonts=	Fixing path to bundled fonts directory.

.include "../../www/firefox91/mozilla-common.mk"
.include "options.mk"

CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/header.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/typelib.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpidl.py
CHECK_INTERPRETER_SKIP+=	lib/firefox-sdk/sdk/bin/xpt.py

CHECK_WRKREF_SKIP+=	lib/${MOZILLA}/omni.ja

MOZILLA=	${PKGBASE}
MOZILLA_ICON=	${WRKSRC}/browser/branding/official/default48.png
MOZILLA_NAME=	TorBrowser

post-extract:
	mv ${WRKDIR}/tor-browser_en-US ${WRKSRC}
#	mv ${WRKDIR}/tor-launcher* ${WRKSRC}/browser/extensions/tor-launcher

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/js/src && autoconf
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC}/${OBJDIR} && touch old-configure.vars
#	Do not fetch Rust Cargo file via network during build
.if !defined(FIREFOX_MAINTAINER)
	mv ${WRKDIR}/dist ${WRKSRC}/${OBJDIR}
.endif

.if defined(FIREFOX_MAINTAINER)
# Create files needed only by the firefox maintainer when updating
# the package
# XXX - manually removing the .*_done files is wrong!
.PHONY: build-list
build-list:
	cd ${WRKSRC}/${OBJDIR}/dist/bin/browser/chrome && \
		find . -type f | sort > ${OUT:Q}

NODE_LIST=	"${WRKDIR}/node.list"
NO_NODE_LIST=	"${WRKDIR}/no-node.list"
NODE_FILES=	"${WRKDIR}/node.flist"

.PHONY: maintainer-files
maintainer-files:
	rm -f ${FILESDIR}/node-wrapper.sh
	V=$$( node -v ) && \
	    printf '#! /bin/sh\n\nVERS=%s\n\nif [ "$$1" = "-v" ] || [ "$$1" = "--version" ]; then\n\tprintf "$${VERS}\\n"\nfi\n\nexit 0\n' $$V \
	    > ${FILESDIR}/node-wrapper.sh && \
	    chmod 0755 ${FILESDIR}/node-wrapper.sh
	rm -f ${WRKDIR}/.build_done ${WRKDIR}/.configure_done
	${MAKE} MAINTAINER_INTERNAL=yes build
	${MAKE} MAINTAINER_INTERNAL=yes OUT="${NO_NODE_LIST}" build-list
	${MAKE} OUT="${NODE_LIST}" build-list
	${DIFF} -u "${NO_NODE_LIST}" "${NODE_LIST}" | \
	    ${AWK} \
	    '/^\+\.\//{ printf("dist/bin/browser/chrome/%s\n", gensub(/^\+\.\//, "", "")) }' \
	    > "${NODE_FILES}"
	cd ${WRKSRC}/${OBJDIR} && tar -c -T "${NODE_FILES}" -z \
	    -f ${FILESDIR}/nodejs-output-${PKGVERSION_NOREV}.tgz
.endif

post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@FIREFOX_ICON@|${MOZILLA}|g'				\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop
	${SED} -e 's|@PREFIX@|${PREFIX}|g'				\
	  < ${FILESDIR}/tor-browser.sh					\
	  > ${WRKDIR}/tor-browser.sh

INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps
INSTALLATION_DIRS+=	${PREFIX}/lib/tor-browser/browser/fontconfig
INSTALLATION_DIRS+=	${PREFIX}/lib/tor-browser/browser/fonts

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/tor-browser.sh \
		${DESTDIR}${PREFIX}/bin/tor-browser
	${INSTALL_DATA} ${WRKDIR}/desktop				\
		${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${MOZILLA_ICON}					\
		${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	${INSTALL_DATA} ${WRKSRC}/tor-browser_en-US/Browser/TorBrowser/Data/fontconfig/fonts.conf \
		${DESTDIR}${PREFIX}/lib/tor-browser/browser/fontconfig
	${INSTALL_DATA} ${WRKSRC}/tor-browser_en-US/Browser/fonts/* \
		${DESTDIR}${PREFIX}/lib/tor-browser/browser/fonts

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
