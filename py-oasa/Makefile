# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:37:34 jihbed Exp $
#

DISTNAME=	oasa-0.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	http://bkchem.zirael.org/download/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://bkchem.zirael.org/download/
COMMENT=	Python library for manipulation of chemical formats
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25 24 23
PYDISTUTILSPKG=	yes

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
