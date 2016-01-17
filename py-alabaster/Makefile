# $NetBSD: Makefile,v 1.1 2015/02/14 09:14:32 jihbed Exp $

DISTNAME=	alabaster-0.7.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/a/alabaster/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bitprophet/alabaster
COMMENT=	Configurable sidebar-enabled Sphinx theme
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-pygments>=0.8:../../textproc/py-pygments

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
