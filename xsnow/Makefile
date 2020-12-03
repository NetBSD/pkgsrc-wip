# $NetBSD$

DISTNAME=	xsnow-3.1.7
CATEGORIES=	x11
MASTER_SITES=	https://ratrabbit.nl/downloads/xsnow/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ratrabbit.nl/ratrabbit/xsnow/
COMMENT=	Create a snowy and Santa-y desktop
LICENSE=	gnu-gpl-v3

USE_LANGUAGES+=	c c++
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
