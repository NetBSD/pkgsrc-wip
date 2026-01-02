# $NetBSD$

DISTNAME=	ffms2-5.0
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=FFMS/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/FFMS/ffms2/
COMMENT=	FFmpeg based source library for easy frame accurate access
LICENSE=	mit AND gnu-lgpl-v2.1
#LICENSE=	OR gnu-gpl-v2 OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	ffms2.pc.in

pre-configure:
	${MKDIR} ${WRKSRC}/src/config
	cd ${WRKSRC} && autoreconf -fiv

.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
