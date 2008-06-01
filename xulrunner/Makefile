# $NetBSD: Makefile,v 1.1.1.1 2008/06/01 13:29:42 tnn2 Exp $
#

DISTNAME=	xulrunner_1.9~rc1.orig
PKGNAME=	xulrunner-1.9rc1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xulrunner/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment

WRKSRC=		${WRKDIR}/xulrunner-1.9~rc1
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl gmake
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-plugin.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nss.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nspr.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-js.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding.pc.in

CONFIGURE_ARGS+=	--enable-application=xulrunner
CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--enable-crypto --enable-default-toolkit=gtk2
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-gnomeui --enable-svg
CONFIGURE_ARGS+=	--enable-svg-renderer=cairo --enable-system-cairo
CONFIGURE_ARGS+=	--enable-mathml --enable-xinerama
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads --enable-xft
CONFIGURE_ARGS+=	--disable-debug --enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--disable-dbus --disable-javaxpcom

MAKE_ENV+=		MOZILLA_PKG_NAME=xulrunner

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
pre-configure: ye-olde-rm-hack
.PHONY: ye-olde-rm-hack
ye-olde-rm-hack:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
