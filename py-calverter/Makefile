# $NetBSD: Makefile,v 1.3 2013/12/06 11:31:35 noud4 Exp $
#

DISTNAME=	pyCalverter-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//S/C/c/}
CATEGORIES=	converters time python
MASTER_SITES=	http://launchpad.net/pycalverter/trunk/1.5/+download/
FETCH_USING=	curl

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://launchpad.net/pycalverter
COMMENT=	Convert date between Hijri, Jalali and Gregorian types of date
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes
REPLACE_PYTHON+=	calverter.py

INSTALLATION_DIRS=	share/doc/py-calverter

post-install:
	${INSTALL_DATA} ${WRKSRC}/USAGE.txt ${DESTDIR}${PREFIX}/share/doc/py-calverter

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
