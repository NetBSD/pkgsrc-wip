# $NetBSD$

DISTNAME=	ecrire-0.2.0
PKGREVISION=	1
CATEGORIES=	editors enlightenment
MASTER_SITES=	https://download.enlightenment.org/rel/apps/ecrire/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://download.enlightenment.org/rel/apps/ecrire/
COMMENT=	Simple text editor for the enlightenment desktop
LICENSE=	gnu-gpl-v3

USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
