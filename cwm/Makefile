# $NetBSD$

GITHUB_TAG=	b6a5b876e7d92d0ff4ef7928b83f740c2dbcc35d
DISTNAME=	cwm
PKGNAME=	cwm-${GITHUB_TAG}
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=chneukirchen/}

MAINTAINER=	cfkoch@edgebsd.org
HOMEPGAGE=	https://github.com/chneukirchen/cwm
COMMENT=	Portable version of the window manager from OpenBSD
LICENSE=	isc

EXTRACT_USING=	gtar
USE_TOOLS+=	pkg-config yacc

WRKSRC=		${WRKDIR}/${PKGNAME}
NO_CONFIGURE=	yes
INSTALL_ENV+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
