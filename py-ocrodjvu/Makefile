# $NetBSD: Makefile,v 1.1 2014/03/26 12:39:00 slitvinov Exp $

DISTNAME=	ocrodjvu-0.7.17
CATEGORIES=	grapics
MASTER_SITES=	https://pypi.python.org/packages/source/o/ocrodjvu/
FETCH_USING=	curl

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	https://pypi.python.org/packages/source/o/ocrodjvu/
COMMENT=	A wrapper for OCR systems to work with djvu files
LICENSE=	gnu-gpl-v2
DEPENDS+=	${PYPKGPREFIX}-djvulibre-[0-9]*:../../wip/py-djvulibre
DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

PYDISTUTILSPKG=	yes

# url2pkg-marker (please do not remove this line.)
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
