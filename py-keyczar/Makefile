# $NetBSD: Makefile,v 1.3 2013/12/14 09:26:56 obache Exp $
#

DISTNAME=	python-keyczar-0.6b.061709
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//S/.061709//}
CATEGORIES= security
MASTER_SITES=	http://keyczar.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/keyczar/
COMMENT=	Toolkit for safe and simple cryptography
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-crypto>=2.0:../../security/py-amkCrypto
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1

WRKSRC=		${WRKDIR}/python-keyczar-0.6b
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/keyczar/alltests.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
