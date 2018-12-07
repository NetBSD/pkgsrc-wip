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

TOOL_DEPENDS+=	python37-[0-9]*:../../lang/python37
TOOL_DEPENDS+=	cbindgen-[0-9]*:../../devel/cbindgen
TOOL_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

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
.if !empty(MACHINE_PLATFORM:MNetBSD-[0-7]**-*) || \
	!empty(MACHINE_PLATFORM:MNetBSD-8.[0-8]*-*)
USE_PKGSRC_GCC_RUNTIME=	yes
.endif


CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
CXXFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
