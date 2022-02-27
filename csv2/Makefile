# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	csv2-0.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=p-ranav/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p-ranav/csv2/
COMMENT=	Fast CSV parser and writer in C++
LICENSE=	mit
WRKSRC=		${WRKDIR}/${DISTNAME}

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++

.include "../../mk/bsd.pkg.mk"
