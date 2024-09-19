# $NetBSD$

DISTNAME=	mkdocs-with-pdf-0.7.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	https://files.pythonhosted.org/packages/2e/57/e9668eef616d901f843ccdbf412a5b2bbcba1b0b8f2f2afc7611db80cc11/

MAINTAINER=     kamelderouiche@yahoo.com
HOMEPAGE=       https://github.com/orzih/mkdocs-with-pdf
COMMENT=        Generate a single PDF file from MkDocs repository
LICENSE=        mit

DEPENDS+=       ${PYPKGPREFIX}-mkdocs>=1.0.4:../../textproc/py-mkdocs
DEPENDS+=       ${PYPKGPREFIX}-weasyprint>=0.44:../../print/py-weasyprint
DEPENDS+=       ${PYPKGPREFIX}-beautifulsoup4>=4.6.3:../../www/py-beautifulsoup4

USE_LANGUAGES=  # none

BUILDLINK_API_DEPENDS.libsass+= libsass>=0.15
.include "../../www/libsass/buildlink3.mk"
.include "../../lang/python/egg.mk"
