# $NetBSD$

DISTNAME=	end_of_eden-0.1.11
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=BigJk/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/BigJk/end_of_eden/
COMMENT=	"Slay the Spire"-like roguelite fully in console
LICENSE=	mit

USE_LANGUAGES=	c
USE_TOOLS+=	pkg-config
MAKE_ENV+=	CGO_ENABLED=1

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
