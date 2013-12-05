# $NetBSD: Makefile,v 1.4 2013/12/05 16:15:04 jihbed Exp $

DISTNAME=	PyArabic-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/A/a/}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyArabic/
EXTRACT_SUFX=	.zip
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyarabic.sourceforge.net/
COMMENT=	Arabic text tools
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
