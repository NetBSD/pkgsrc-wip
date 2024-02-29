# $NetBSD$

DISTNAME=	btop-1.2.13.20240218
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
#GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_TAG=	6c667402907171f3ba7ebb637e553cc6f66f4e66

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GCC_REQD+=	10
CXXFLAGS+=	-DNDEBUG

MAKE_ARGS=	STRIP=true VERBOSE=true

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
