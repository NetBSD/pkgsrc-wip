# $NetBSD: Makefile,v 1.1.1.1 2010/05/22 23:04:51 jihbed Exp $
#

DISTNAME=	python-keyczar-0.6b.061709
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//S/.061709//}
CATEGORIES= security
MASTER_SITES=	http://keyczar.googlecode.com/files/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/keyczar/
COMMENT=	Toolkit for safe and simple cryptography
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/python-keyczar-0.6b
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} tests/keyczar/alltests.py

.include "../../lang/python/extension.mk"
BUILDLINK_API_DEPENDS.py-amkCrypto+=	${PYPKGPREFIX}-amkCrypto>=2.0.1nb1
.include "../../security/py-amkCrypto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
