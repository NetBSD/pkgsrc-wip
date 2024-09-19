# $NetBSD$

DISTNAME=	scanless-1.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scanless/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/vesche/scanless
COMMENT=	Online port scan scraper
LICENSE=	unlicense

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.6.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-requests>=2.14.2:../../devel/py-requests

.include "../../wip/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
