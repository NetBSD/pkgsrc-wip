# $NetBSD$

GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}
DISTNAME=	pystring-1.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=imageworks/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/imageworks/pystring/
COMMENT=	Pythons string methods for C++ std::string
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LIBTOOL=	yes
USE_LANGUAGES=	c++
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	include/pystring lib

post-install:
	${RUN} ${INSTALL_DATA} ${WRKSRC}/pystring.h \
		${DESTDIR}${PREFIX}/include/pystring

.include "../../mk/bsd.pkg.mk"
