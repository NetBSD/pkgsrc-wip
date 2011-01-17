# $NetBSD: Makefile,v 1.1.1.1 2011/01/17 22:00:14 jihbed Exp $
#

DISTNAME=	PyArabic-0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^Py//S/A/a/}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyArabic/
EXTRACT_SUFX=	.zip#md5=22fb895023c12f669781b96df0a984fa

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyarabic.sourceforge.net/
COMMENT=	Arabic text tools
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
