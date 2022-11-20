# $NetBSD$

GITHUB_PROJECT=	shell-term-background
DISTNAME=	term-background-1.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_GITHUB:=rocky/}
GITHUB_RELEASE=	1.0.1
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/rocky/shell-term-background/
COMMENT=	Terminal has a dark or light background Topics
LICENSE=	gnu-gpl-v2

post-extract:
	${CP} ${FILESDIR}/__pkginfo__.py ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
