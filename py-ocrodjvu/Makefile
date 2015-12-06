# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:49 thomasklausner Exp $

DISTNAME=	ocrodjvu-0.7.17
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	https://pypi.python.org/packages/source/o/ocrodjvu/

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://pypi.python.org/pypi/ocrodjvu/
COMMENT=	Wrapper for OCR systems to work with djvu files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-djvulibre-[0-9]*:../../wip/py-djvulibre
DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-djvulibre

REPLACE_PYTHON+=	lib/logger.py

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
