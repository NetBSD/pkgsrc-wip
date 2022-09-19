# $NetBSD$

DISTNAME=	3.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=swisskyrepo/}
GITHUB_PROJECT=	PayloadsAllTheThings
GITHUB_TAG=	refs/tags/3.0
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/swisskyrepo/PayloadsAllTheThings/
COMMENT=	Collection of payloads and bypasses for Web Application Security
LICENSE=	mit

USE_TOOLS+=	pax

WRKSRC=		${WRKDIR}/PayloadsAllTheThings-3.0

INSTALLATION_DIRS=	share/PayloadsAllTheThings


NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${PAX} -rw * \
	${DESTDIR}${PREFIX}/share/PayloadsAllTheThings/

.include "../../mk/bsd.pkg.mk"
