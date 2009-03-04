# $NetBSD: Makefile,v 1.3 2009/03/04 10:04:12 yhardy Exp $

MOZILLA=		icecat
MOZILLA_BIN=		icecat-bin
COMMENT=		Lightweight gecko-based web browser

PKG_DESTDIR_SUPPORT=	user-destdir

MOZILLA_USE_GTK2=	# yes
MOZILLA_USE_XFT=	YES

INSTALLATION_DIRS=	lib/pkgconfig

CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.6.4
.include "../../databases/sqlite3/buildlink3.mk"

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

# Pull in standard firefox build framework, and override some things below
.include "../../www/firefox/Makefile-firefox.common"

MAINTAINER=		pkgsrc-users@NetBSD.org
MOZ_VER=		3.0.6
MOZILLA_BIN=		icecat-bin

DISTNAME=		icecat-${MOZ_VER}-g1
MASTER_SITES=		http://ftp.gnu.org/gnu/gnuzilla/${MOZ_VER}-g1/
MASTER_SITES+=		http://www.gnu.org/software/gnuzilla/
EXTRACT_SUFX=		.tar.bz2
HOMEPAGE=		http://www.gnu.org/software/gnuzilla/
WRKSRC=			${WRKDIR}/${DISTNAME}

DISTFILES=      	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		icecat.png

DISTINFO_FILE=		${.CURDIR}/../../wip/icecat/distinfo
PATCHDIR=		${.CURDIR}/../../www/firefox3/patches

CONFLICTS=		firefox3

PLIST_SUBST+=		MOZILLA=${MOZILLA:Q}
PLIST_SUBST+=		MOZILLA_BIN=${MOZILLA_BIN:Q}
FILES_SUBST+=		MOZILLA=${MOZILLA:Q}
FILES_SUBST+=		MOZILLA_BIN=${MOZILLA_BIN:Q}

post-extract: copy-pkgconfig copy-icon

.PHONY: copy-pkgconfig
copy-pkgconfig:
	cp ${.CURDIR}/../../wip/icecat/files/*.pc ${WRKSRC:Q}/build/unix

MOZ_ICON_DIR=	${WRKSRC:Q}/dist/bin/chrome/icons/default
MOZ_ICON=	${MOZ_ICON_DIR}/default.png

.PHONY: copy-icon
copy-icon:
	if [ ! -e ${MOZ_ICON_DIR} ]; then		\
		mkdir -p ${MOZ_ICON_DIR};		\
	fi
	if [ ! -e ${MOZ_ICON} ]; then			\
		cp ${DISTDIR:Q}/icecat.png ${MOZ_ICON};	\
	fi

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
pre-configure: create-dummy-c-sdk
.PHONY: create-dummy-c-sdk
create-dummy-c-sdk:
	mkdir -p ${WRKSRC:Q}/directory/c-sdk
	touch ${WRKSRC:Q}/directory/c-sdk/configure.in

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
pre-configure: ye-olde-rm-hack
.PHONY: ye-olde-rm-hack
ye-olde-rm-hack:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

# Link browser.xpt
post-build: stage-package
.PHONY: stage-package
stage-package:
	cd ${WRKSRC}/browser/installer && \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} stage-package
	cp ${WRKSRC}/dist/icecat/components/browser.xpt \
	   ${WRKSRC}/dist/bin/components/browser.xpt

# Install libjemalloc.so which is needed on Linux.
.if ${OPSYS} == "Linux"
post-install: install-libjemalloc
.PHONY: install-libjemalloc
install-libjemalloc:
	${INSTALL_LIB} ${WRKSRC}/dist/lib/libjemalloc.so \
	  ${DESTDIR}${PREFIX}/lib/${MOZILLA}/libjemalloc.${SO_SUFFIX}
.endif

INSTALLATION_DIRS+=	lib/${MOZILLA}/modules

# Can't use system PNG because it doesn't have APNG support?
CONFIGURE_ARGS+=	--without-system-png
# Override www/firefox's idea of toolkit
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
# Is dbus support useful for anything?
CONFIGURE_ARGS+=	--disable-dbus
# Avoids needing curl on Linux
CONFIGURE_ARGS+=	--disable-crashreporter

.include "../../mk/bsd.pkg.mk"
