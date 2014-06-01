# $NetBSD: Makefile,v 1.5 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	PyArabic-0.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//S/A/a/}
CATEGORIES=	textproc python
MASTER_SITES=	https://pypi.python.org/packages/source/P/PyArabic/
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyarabic.sourceforge.net/
COMMENT=	Arabic text tools
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
