# $NetBSD: Makefile,v 1.54 2023/11/12 13:21:31 wiz Exp $

DISTNAME=	Enigma-1.30-src
PKGNAME=	${DISTNAME:S/E/e/:S/-src//}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Enigma-Game/}
GITHUB_PROJECT=	Enigma

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/enigma/
COMMENT=	Puzzle game similar to Oxyd/Rock'n'Roll/Marble Madness
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
TOOL_DEPENDS+=	gettext-tools-[0-9]*:../../devel/gettext-tools

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++11
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		aclocal autoconf autoheader automake gmake
GNU_CONFIGURE=		yes

WRKSRC=	${WRKDIR}/${DISTNAME:S/eni/Eni/:S/-src//}

#CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no

LDFLAGS.SunOS+=	-lsocket -lnsl

pre-configure:
	cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh
#	cd ${WRKSRC} && autoheader && aclocal -I m4 && automake --add-missing --foreign --copy && autoconf
#	cd ${WRKSRC}/lib-src/enet && autoheader && aclocal -I m4 && automake --add-missing --foreign --copy && autoconf
#	cd ${WRKSRC}/lib-src/zipios++ && aclocal && automake --add-missing --foreign --copy && autoconf

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
BUILDLINK_API_DEPENDS.png+=		png>=1.2.7
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
