# $NetBSD$

DISTNAME=	pinentry-dmenu-0.2.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=ritze/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ritze/pinentry-dmenu/
COMMENT=	A pinentry program with the charm of dmenu
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/pinentry-dmenu-0.2.2

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

USE_X11=yes

#.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
#.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/libconfig/buildlink3.mk"
.include "../../security/libassuan2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
