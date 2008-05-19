# $NetBSD: Makefile,v 1.8 2008/05/19 15:05:39 tnn2 Exp $

MOZILLA=		firefox
COMMENT=		Lightweight gecko-based web browser

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

MOZ_VER=		3.0rc1

DESCR_SRC=		${.CURDIR}/../../www/firefox/DESCR

DISTINFO_FILE=		${.CURDIR}/../../wip/firefox/distinfo
PATCHDIR=		${.CURDIR}/../../wip/firefox/patches

# Need this to be able to reuse existing firefox pkgsrc infrastructure
# Note that we don't currently install the SDK.
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
	cp ${WRKSRC}/dist/firefox/components/browser.xpt \
	   ${WRKSRC}/dist/bin/components/browser.xpt

INSTALLATION_DIRS+=	lib/${MOZILLA}/modules

# Can't use system PNG because it doesn't have APNG support?
CONFIGURE_ARGS+=	--without-system-png
# Override www/firefox's idea of toolkit
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
# Is dbus support useful for anything?
CONFIGURE_ARGS+=	--disable-dbus

.include "../../mk/bsd.pkg.mk"
