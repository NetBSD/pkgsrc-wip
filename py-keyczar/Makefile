# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:48 thomasklausner Exp $

DISTNAME=	keyczar-python-0.71d-09062013
PKGNAME=	keyczar-0.7.1d-09062013
EGG_NAME=	python_keyczar-0.71c
CATEGORIES=	security
MASTER_SITES=	http://keyczar.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/keyczar/
COMMENT=	Toolkit for safe and simple cryptography
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.3.1:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-m2crypto>=0.21.1:../../security/py-m2crypto
DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1

WRKSRC=		${WRKDIR}/keyczar-python

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-m2crypto

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/keyczar/alltests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
