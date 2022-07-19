# $NetBSD: Makefile,v 1.10 2022/07/14 23:46:27 dholland Exp $

DISTNAME=	wxWidgets-3.2.0
PKGNAME=	${DISTNAME:S/wxWidgets/wxGTK32/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=wxWidgets/}
GITHUB_PROJECT=	wxWidgets
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dbj@NetBSD.org
HOMEPAGE=	https://www.wxwidgets.org/
COMMENT=	Cross-platform wxWidgets GUI library (3.2 stable branch)
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=		pkg-config msgfmt
USE_CMAKE=		yes
USE_LANGUAGES=		c c++
CMAKE_ARGS+=		-DCMAKE_DISABLE_PRECOMPILE_HEADERS:BOOL=ON

# didn't find all places hardcoding libdl, so force them away
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

TO_UNWRAP=	${WRKSRC}/lib/wx/config/gtk3-unicode-3.2

# Installation rules in cmake are not using DESTDIR properly, do it manually
# https://github.com/wxWidgets/wxWidgets/issues/22647
# CMake Error: failed to create symbolic link '/usr/pkg/bin/wx-config': Permission denied
# CMake Error: failed to create symbolic link '/usr/pkg/bin/wxrc': Permission denied
post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s ../lib/wx/config/gtk3-unicode-3.2 wx-config
	cd ${DESTDIR}${PREFIX}/bin && ${LN} -s wxrc-3.2 wxrc
post-build:
	${SED} -e "s,EGREP=.*,EGREP=${EGREP}," \
		-e 's/echo.*cc\"/echo \"${CC}\"/' \
		-e 's/echo.*c\+\+\"/echo \"${CXX}\"/' \
		-e 's/echo.*c\+\+\ -o\"/echo \"${CXX} -o\"/' \
		${TO_UNWRAP} > ${TO_UNWRAP}.new && \
	${MV} ${TO_UNWRAP}.new ${TO_UNWRAP} && \
	${CHMOD} 755 ${TO_UNWRAP}

.include "../../mk/bsd.prefs.mk"

# https://github.com/wxWidgets/wxWidgets/issues/22646
.if ${OPSYS} != "Linux"
CMAKE_ARGS+=		-DwxUSE_JOYSTICK:BOOL=OFF
.endif

.if ${OPSYS} != "Darwin"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif

.include "../../archivers/libmspack/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/gspell/buildlink3.mk"
# curl not checked by cmake but used by webrequest_curl.h
# https://github.com/wxWidgets/wxWidgets/issues/22648
.include "../../www/curl/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
