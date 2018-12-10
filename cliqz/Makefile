# $NetBSD$

DISTNAME=	cliqz-${DISTVERSION}
DISTVERSION=	1.23.3
CATEGORIES=	www
MASTER_SITES+=	${MASTER_SITE_GITHUB:=cliqz-oss/}
GITHUB_PROJECT=	browser-f
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTFILES=	adult-domains.bin \
		cliqz@cliqz.com.xpi \
		https-everywhere@cliqz.com.xpi \
		gdprtool@cliqz.com.xpi \
		${DISTNAME}${EXTRACT_SUFX}

EXTRACT_USING=	bsdtar
#EXTRACT_SUFX=	.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	fox@NetBSD.org
HOMEPAGE=	https://cliqz.com/en/desktop
COMMENT=	Secure browser (Mozilla based) with built-in quick search
LICENSE=	mpl-2.0

TOOL_DEPENDS+=	python37-[0-9]*:../../lang/python37
TOOL_DEPENDS+=	cbindgen-[0-9]*:../../devel/cbindgen
TOOL_DEPENDS+=	nodejs-[0-9]*:../../lang/nodejs

BUILD_DEPENDS+=	yasm>=1.1:../../devel/yasm

USE_TOOLS+=	pkg-config perl gmake autoconf213 unzip zip bash pax
USE_LANGUAGES+=	c99 gnu++14

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTVERSION}

CLIQZ_CHANNEL=		release
# If the DISTVERSION is updated, make sure to update the last build id from
# fetch -qo - https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/lastbuildid
CLIQZ_LAST_BUILD_ID=	20181116003917
CLIQZ_ICON=		cliqz.png
CLIQZ_ICON_SRC=		${WRKSRC}/mozilla-release/browser/branding/cliqz/default48.png
MOZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/mozilla.desktop
CLIQZ_DESKTOP=		${WRKSRC}/mozilla-release/toolkit/mozapps/installer/linux/rpm/cliqz.desktop
CLIQZ_PLUGIN_SUFX=	@cliqz.com.xpi

SITES.adult-domains.bin= \
	https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/
SITES.cliqz${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/${CLIQZ_LAST_BUILD_ID}/
SITES.https-everywhere${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/${CLIQZ_LAST_BUILD_ID}/
SITES.gdprtool${CLIQZ_PLUGIN_SUFX}= \
	https://repository.cliqz.com/dist/${CLIQZ_CHANNEL}/${DISTVERSION}/${CLIQZ_LAST_BUILD_ID}/

MAKE_ENV+=	CQZ_RELEASE_CHANNEL=${CLIQZ_CHANNEL}
MAKE_ENV+=	CQZ_BUILD_ID=${CLIQZ_LAST_BUILD_ID}

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--target=${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_PLATFORM}

CHECK_PORTABILITY_SKIP+=	build-tools/scripts/l10n/release_repacks.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/intl/icu/source/configure
CHECK_PORTABILITY_SKIP+=	mozilla-release/modules/pdfium/update.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/libpkix/libpkix.sh
CHECK_PORTABILITY_SKIP+=	mozilla-release/security/nss/tests/multinit/multinit.sh

CHECK_WRKREF_SKIP+=		lib/cliqz/chrome/toolkit/content/global/buildconfig.html

REPLACE_BASH+=	magic_build_and_package.sh

# for lang/gcc6
GCC_REQD+=	6.1

.if !empty(MACHINE_PLATFORM:MNetBSD-[0-7]**-*) || \
	!empty(MACHINE_PLATFORM:MNetBSD-8.[0-8]*-*)
USE_PKGSRC_GCC_RUNTIME=	yes
.endif

CFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS -D__HAVE_INLINE___ISINF
CXXFLAGS+=	-D_GLIBCXX_INCLUDE_NEXT_C_HEADERS -D__HAVE_INLINE___ISINF
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/cliqz ${COMPILER_RPATH_FLAG}${PREFIX}/lib

NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/cliqz-bin
NOT_PAX_MPROTECT_SAFE+=	lib/cliqz/plugin-container

post-extract:
	${CP} ${DISTDIR}/adult-domains.bin ${WRKSRC}
	${MKDIR} ${WRKSRC}/obj/dist/bin/browser/features
	${CP} ${DISTDIR}/cliqz${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/https-everywhere${CLIQZ_PLUGIN_SUFX} \
		${DISTDIR}/gdprtool${CLIQZ_PLUGIN_SUFX} \
		${WRKSRC}/obj/dist/bin/browser/features

post-patch:
	${SED}  -e 's/@MOZ_APP_DISPLAYNAME@/Cliqz Internet/g' \
		-e 's/@MOZ_APP_NAME@/cliqz/g' \
		-e '/Icon=cliqz/ s/cliqz/${CLIQZ_ICON}/' \
		-e '/StartupWMClass/d' \
		< ${MOZ_DESKTOP} \
		> ${CLIQZ_DESKTOP}
	${ECHO} 'ac_add_options --target=${MACHINE_GNU_PLATFORM}' >> \
		${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig
	${ECHO} 'ac_add_options --host=${MACHINE_GNU_PLATFORM}' >> \
		${WRKSRC}/mozilla-release/browser/config/cliqz.mozconfig

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./magic_build_and_package.sh

INSTALLATION_DIRS+=	share/applications share/pixmaps bin lib/cliqz
do-install:
	cd ${WRKSRC}/obj/dist/cliqz && ${PAX} -wr * ${DESTDIR}${PREFIX}/lib/cliqz
	${FIND} . \(	-name \*.png -or \
			-name \*.gif -or \
			-name \*.jpg -or \
			-name \*.js  -or \
			-name \*.jsm -or \
			-name \*.xhtml -or \
			-name \*.html -or \
			-name \*.css -or \
			-name \*.txt -or \
			-name \*.svg -or \
			-name \*.dic -or \
			-name \*.ftl -or \
			-name \*.xul -or \
			-name \*.xml -or \
			-name \*.bcmap -or \
			-name \*.wav -or \
			-name \*.aff -or \
			-name \*.ent -or \
			-name \*.dtd -or \
			-name \*.ico -or \
			-name \*.cur -or \
			-name \*.xsl -or \
			-name \*.js.mem -or \
			-name LICENSE_THIRDPARTY -or \
			-name LICENSE -or \
			-name permissions -or \
			-name \*.json \
		\) \
	-type f \
	-exec ${CHMOD} 0644 '{}' \;
	${FIND} . \(	-name responsive.html \
		\) \
	-type f \
	-exec ${CHMOD} 0755 '{}' \;

post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/cliqz
	${ECHO} '${PREFIX}/lib/cliqz/cliqz "$$@"' >> ${DESTDIR}${PREFIX}/bin/cliqz
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/cliqz
	${INSTALL_DATA} ${CLIQZ_DESKTOP} ${DESTDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${CLIQZ_ICON_SRC} ${DESTDIR}${PREFIX}/share/pixmaps/${CLIQZ_ICON}

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=       libevent>=1.1
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
BUILDLINK_API_DEPENDS.nspr+=   nspr>=4.19
.include "../../devel/nspr/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
BUILDLINK_API_DEPENDS.nss+=     nss>=3.38
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_DEPMETHOD.clang=     build
BUILDLINK_API_DEPENDS.clang+=  clang>=6.0.1nb1
.include "../../lang/clang/buildlink3.mk"
BUILDLINK_DEPMETHOD.rust=      build
BUILDLINK_API_DEPENDS.rust+=   rust>=1.24.0
.include "../../lang/rust/buildlink3.mk"
BUILDLINK_API_DEPENDS.libvpx+= libvpx>=1.3.0
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../net/libIDL/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
BUILDLINK_API_DEPENDS.pixman+= pixman>=0.25.2
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
