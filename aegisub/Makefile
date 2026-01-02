# $NetBSD: Makefile,v 1.1 2015/01/14 17:16:08 thomasklausner Exp $

DISTNAME=	aegisub-3.4.2
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=TypesettingTools/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	Aegisub

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.aegisub.org/
COMMENT=	Free, cross-platform tool for creating and modifying subtitles
LICENSE=	original-bsd

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

#Run-time dependency libpulse found: NO (tried pkgconfig and cmake)
#Run-time dependency alsa found: NO (tried pkgconfig and cmake)
#Run-time dependency portaudio-2.0 found: NO (tried pkgconfig and cmake)
#Run-time dependency openal found: NO (tried pkgconfig and cmake)

# needed by 3.4+
pre-configure:
	${CP} ${FILESDIR}/git_version.h ${WRKSRC}

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
BUILDLINK_API_DEPENDS.LuaJIT2+=	LuaJIT2>=2.1.1713773202nb1
.include "../../lang/LuaJIT2/buildlink3.mk"
.include "../../math/fftw/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/uchardet/buildlink3.mk"
.include "../../wip/ffms2/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
