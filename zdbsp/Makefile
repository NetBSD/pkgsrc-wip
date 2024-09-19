# $NetBSD$

DISTNAME=	zdbsp-1.19
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=rheit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://github.com/rheit/zdbsp/
COMMENT=	ZDoom's internal node builder
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c99 c++03

USE_CMAKE=		yes
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zdbsp ${DESTDIR}${PREFIX}/bin/zdbsp

.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
