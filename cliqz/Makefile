# $NetBS$

DISTNAME=	cliqz-${DISTVERSION}
DISTVERSION=	1.23.3
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_GITHUB:=cliqz-oss/}
GITHUB_PROJECT=	browser-f
GITHUB_TAG=	${PKGVERSION_NOREV}
EXTRACT_USING=	bsdtar
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://cliqz.com/en/desktop
COMMENT=	Secure browser (Mozilla based) with built-in quick search
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT} \
		python37-[0-9]*:../../lang/python37 \
		cbindgen-[0-9]*:../../devel/cbindgen \
		nodejs-[0-9]*:../../lang/nodejs \

BUILD_DEPENDS+=	yasm>=1.1:../../devel/yasm 

USE_TOOLS+=	pkg-config perl gmake autoconf213 unzip zip bash
USE_LANGUAGES+=	c99 c++14

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTVERSION}

#HAS_CONFIGURE=	 NO

CLIQZ_CHANNEL=		release
# If the DISTVERSION is updated, make sure to update the last build id from
# fetch -qo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20181116003917
CLIQZ_ICON=		cliqz.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/${PORTNAME}/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop

CONFIGURE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
CONFIGURE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}

.include "../../mk/bsd.prefs.mk"

CHECK_PORTABILITY_SKIP+=	build-tools/scripts/l10n/release_repacks.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	mozilla-release/modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/multinit/multinit.sh

# for lang/gcc6
GCC_REQD+=	6.1
USE_PKGSRC_GCC_RUNTIME=	yes

CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
CXXFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

.include "../../archivers/bzip2/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=	nspr>=4.19
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=     nss>=3.38
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=	build
BUILDLINK_API_DEPENDS.clang+=	clang>=6.0.1nb1
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.rust=	build
BUILDLINK_API_DEPENDS.rust+=	rust>=1.24.0
.include "../../lang/rust/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvpx+=	libvpx>=1.3.0
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+=	pixman>=0.25.2
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/pyversion.mk"

pre-fetch:
	${ECHO} ${LDFLAGS}
	${ECHO} ${CONFIGURE_ENV}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
