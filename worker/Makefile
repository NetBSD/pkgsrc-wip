# $NetBSD$

DISTNAME=	worker-4.12.1
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	dvollen@gmail.com
HOMEPAGE=	http://www.boomerangsworld.de/cms/worker/downloads/
COMMENT=	Orthodox file manager for the X Window System
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

REPLACE_BASH+=	scripts/*.sh scripts/*r
REPLACE_PYTHON+=	scripts/*.py
USE_TOOLS+=	bash:run

# Should this be an option instead?
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
