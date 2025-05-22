# $NetBSD$

DISTNAME=	evisum-0.6.0
PKGREVISION=	1
CATEGORIES=	sysutils enlightenment
MASTER_SITES=	https://download.enlightenment.org/rel/apps/evisum/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://download.enlightenment.org/rel/apps/evisum/
COMMENT=	System Monitor for the enlightenment desktop
LICENSE=	isc

USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config

.include "../../devel/meson/build.mk"
.include "../../wip/efl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
