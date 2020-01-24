# $NetBSD: Makefile,v 1.6 2015/02/22 22:46:00 jihbed Exp $

DISTNAME=	PyArabic-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/Py//tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/PyArabic/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyarabic.sourceforge.net/
COMMENT=	Arabic text tools
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/PyArabic-0.5

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
