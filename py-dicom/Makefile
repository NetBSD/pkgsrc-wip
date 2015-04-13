# $NetBSD: Makefile,v 1.3 2015/04/13 23:22:02 othyro Exp $

DISTNAME=	pydicom-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	biology
MASTER_SITES=	https://pydicom.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://code.google.com/p/pydicom/
COMMENT=	Read, modify and write DICOM files with python code
LICENSE=	mit


USE_TOOLS+=	bash
USE_LANGUAGES=	# none

REPLACE_BASH+=	dicom/test/shell_all
REPLACE_PYTHON+=	dicom/contrib/dicom_dao.py

PYTHON_VERSIONS_ACCEPTED= 27

do-test:
	${RUN} cd ${WRKSRC}/dicom/test; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run_test.py

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.6.2:../../converters/py-simplejson

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
