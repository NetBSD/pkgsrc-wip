# $NetBSD: Makefile,v 1.8 2009/07/18 22:52:00 tnn2 Exp $
#

DISTNAME=	xulrunner-${XULRUNNER_VER}-source
PKGNAME=	${DISTNAME:S/-source//}
XULRUNNER_VER=	1.9.0.11
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_MOZILLA:=xulrunner/releases/${XULRUNNER_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://developer.mozilla.org/en/docs/XULRunner
COMMENT=	XML User Interface Language runtime environment

WRKSRC=		${WRKDIR}/mozilla
GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config perl gmake autoconf213
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=		zip>=2.3:../../archivers/zip

PKG_DESTDIR_SUPPORT=	user-destdir
CHECK_PORTABILITY_SKIP=	security/nss/tests/libpkix/libpkix.sh

PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul-unstable.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/libxul.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed-embedding.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-gtkmozembed.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-js.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nspr.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-nss.pc.in
PKGCONFIG_OVERRIDE+=	xulrunner/installer/mozilla-plugin.pc.in

PRIVILEGED_STAGES=	clean
CHECK_SHLIBS_SUPPORTED=	no # XXX

CONFIG_GUESS_OVERRIDE=	build/autoconf/config.guess
CONFIG_GUESS_OVERRIDE+=	nsprpub/build/autoconf/config.guess
CONFIG_SUB_OVERRIDE=	build/autoconf/config.sub
CONFIG_SUB_OVERRIDE+=	nsprpub/build/autoconf/config.sub
CONFIG_STATUS_OVERRIDE=	build/config.status
CONFIG_STATUS_OVERRIDE+=nsprpub/config.status

CONFIGURE_ARGS+=	--enable-application=xulrunner
CONFIGURE_ARGS+=	--disable-tests --disable-pedantic
CONFIGURE_ARGS+=	--disable-debug --enable-crypto
CONFIGURE_ARGS+=	--enable-optimize=-O2 --with-pthreads
CONFIGURE_ARGS+=	--disable-gnomevfs --disable-gnomeui
CONFIGURE_ARGS+=	--disable-dbus --disable-javaxpcom
CONFIGURE_ARGS+=	--enable-default-toolkit=cairo-gtk2
CONFIGURE_ARGS+=	--enable-svg --enable-mathml
CONFIGURE_ARGS+=	--enable-system-cairo --enable-system-lcms
CONFIGURE_ARGS+=	--with-system-jpeg
CONFIGURE_ARGS+=	--with-system-zlib --with-system-bz2
CONFIGURE_ARGS+=	--enable-system-sqlite
CONFIGURE_ARGS+=	--disable-crashreporter

MAKE_ENV+=		MOZILLA_PKG_NAME=xulrunner

pre-configure:
	cd ${WRKSRC} && autoconf
	cd ${WRKSRC}/nsprpub && autoconf

# Makefiles sometimes call "rm -f" without more arguments. Kludge around ...
.PHONY: create-rm-wrapper
pre-configure: create-rm-wrapper
create-rm-wrapper:
	printf '#!/bin/sh\n[ "$$*" = "-f" ] && exit 0\nexec /bin/rm $$@\n' > \
	  ${WRAPPER_DIR}/bin/rm
	chmod +x ${WRAPPER_DIR}/bin/rm

post-install:
	cd ${WRKSRC}/dist/include && \
	  ${INSTALL_DATA} `find js -name "*.h" -print` js/jsproto.tbl \
	  ${DESTDIR}${PREFIX}/include/xulrunner/unstable

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.sqlite3+=	sqlite3>=3.5.9
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
