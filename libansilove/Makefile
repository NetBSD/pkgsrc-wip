# $NetBSD$

DISTNAME=	libansilove-1.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ansilove/}

MAINTAINER=	fred@statdns.com
HOMEPAGE=	https://www.ansilove.org/
COMMENT=	Library for converting ANSI, ASCII, and other formats to PNG
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man3

post-install:
	${RUN}${INSTALL_MAN} ${WRKSRC}/libansilove.3 \
	                     ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../graphics/gd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
