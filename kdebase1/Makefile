# $NetBSD$

DISTNAME=	kdebase-1.1.2
PKGNAME=	${DISTNAME:S/-1/1-1/}
CATEGORIES=	x11
MASTER_SITES=	http://nishi.boats/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://github.com/nishiowo/kde1-kdebase
COMMENT=	KDE base for 1.x
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	kdelibs1-[0-9]*:../../wip/kdelibs1
DEPENDS+=	ncurses-[0-9]*:../../devel/ncurses

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/kdelibs1/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
