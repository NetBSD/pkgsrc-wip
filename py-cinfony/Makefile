# $NetBSD: Makefile,v 1.3 2013/06/04 07:45:22 thomasklausner Exp $

DISTNAME=	cinfony-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://cinfony.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/cinfony/
COMMENT=	Common API for several cheminformatics toolkits
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test/testall.py

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
