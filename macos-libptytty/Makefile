# $NetBSD$ - MacOS/Darwin

DISTNAME=	libptytty-2.0
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.schmorp.de/libptytty/

MAINTAINER=	pkgsrc@maileffect.de
HOMEPAGE=	http://dist.schmorp.de/libptytty/
COMMENT=	OS independent and secure pty/tty and utmp/wtmp/lastlog handling
#LICENSE=	

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libptytty.pc.in

.include "../../mk/bsd.pkg.mk"
