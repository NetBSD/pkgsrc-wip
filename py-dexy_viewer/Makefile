# $NetBSD: Makefile,v 1.2 2013/09/05 01:20:36 jihbed Exp $

DISTNAME=	dexy_viewer-0.0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dexy_viewer/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dexy.it/
COMMENT=	Document Automation viewer
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-inflection>=0.2.0:../../wip/py-inflection

WRKSRC=		${WRKDIR}/dexy_viewer-0.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
