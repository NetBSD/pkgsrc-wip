# $NetBSD$

DISTNAME=	kdeutils-1.1.2
PKGNAME=	${DISTNAME:S/-1/1-1/}
CATEGORIES=	x11
MASTER_SITES=	http://nishi.boats/

MAINTAINER=	nishi@nishi.boats
HOMEPAGE=	https://github.com/nishiowo/kde1-kdeutils
COMMENT=	KDE utilities for 1.x
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

DEPENDS+=	kdebase1-[0-9]*:../../wip/kdebase1

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

.include "../../devel/cmake/build.mk"
.include "../../wip/kdelibs1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
