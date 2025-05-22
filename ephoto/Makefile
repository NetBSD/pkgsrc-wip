# $NetBSD$

DISTNAME=	ephoto-1.6.0
PKGREVISION=	1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	https://download.enlightenment.org/rel/apps/ephoto/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://download.enlightenment.org/rel/apps/ephoto/
COMMENT=	Image viewer and editor for the enlightenment desktop
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
