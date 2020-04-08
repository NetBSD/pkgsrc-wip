# $NetBSD$

DISTNAME=	sowm-1.6
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=dylanaraps/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dylanaraps/sowm/
COMMENT=	Itsy bitsy floating window manager
LICENSE=	mit

INSTALLATION_DIRS+=	bin

DEPENDS+=	dmenu-[0-9]*:../../x11/dmenu
DEPENDS+=	st-term-[0-9]*:../../x11/st-term
DEPENDS+=	scrot-[0-9]*:../../graphics/scrot

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
