# $NetBSD: Makefile,v 1.1 2014/03/15 22:47:55 jihbed Exp $

DISTNAME=	hieroglyph-0.6.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hieroglyph/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://files.pythonhosted.org/packages/source/h/hieroglyph/
COMMENT=	Sphinx which builds HTML5 slides from ReStructured Text documents
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.2.1:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
