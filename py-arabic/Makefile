# $NetBSD: Makefile,v 1.2 2011/12/29 00:22:12 jihbed Exp $
#

DISTNAME=	PyArabic-0.3
PKGNAME=	${PYPKGPREFIX}-arabic-0.3
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/P/PyArabic/
EXTRACT_SUFX=	.zip#md5=377d0f5798b8bcb6b439010bbbb3e0ed

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://pyarabic.sourceforge.net/
COMMENT=	Arabic text tools
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
