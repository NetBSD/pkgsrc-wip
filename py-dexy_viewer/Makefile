# $NetBSD: Makefile,v 1.1 2013/09/05 01:19:29 jihbed Exp $

DISTNAME=	dexy_viewer-0.0.4
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	https://pypi.python.org/packages/source/d/dexy_viewer/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dexy.it/
COMMENT=	Document Automation
LICENSE=	mit

DEPENDS+=    ${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=    ${PYPKGPREFIX}-inflection>=0.2.0:../../wip/py-inflection

WRKSRC=		${WRKDIR}/dexy_viewer-0.0.4
USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
