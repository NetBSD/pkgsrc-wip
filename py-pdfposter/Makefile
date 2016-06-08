# $NetBSD: Makefile,v 1.1 2014/04/18 21:25:07 thomasklausner Exp $

DISTNAME=	pdftools.pdfposter-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pdftools.//}
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pdftools.pdfposter/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/pdftools.pdfposter
COMMENT=	Scale and tile PDF images/pages to print on multiple pages
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Pdf>=1.10:../../print/py-Pdf

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
