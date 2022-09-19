# $NetBSD$

DISTNAME=	2022.3
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=danielmiessler/}
GITHUB_PROJECT=	SecLists
GITHUB_TAG=	refs/tags/2022.3
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	nebbionegiuseppe@gmail.com
HOMEPAGE=	https://github.com/danielmiessler/SecLists/
COMMENT=	Collection of multiple types of lists used during security assessments
LICENSE=	mit

USE_TOOLS+=	pax

WRKSRC=	${WRKDIR}/SecLists-2022.3

INSTALLATION_DIRS=	share/SecLists

NO_CONFIGURE=	yes
NO_BUILD=	yes


do-install:
	cd ${WRKSRC} && ${PAX} -rw * \
	${DESTDIR}${PREFIX}/share/SecLists/


.include "../../mk/bsd.pkg.mk"
