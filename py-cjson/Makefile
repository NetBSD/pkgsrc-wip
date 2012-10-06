# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:26 asau Exp $
#

DISTNAME=	python-cjson-1.0.5.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//S/.tar//}
CATEGORIES=	textproc python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-cjson/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://ag-projects.com/
COMMENT=	Fast JSON encoder/decoder for Python
LICENSE=	gnu-lgpl-v2

WRKSRC=	${WRKDIR}/python-cjson-1.0.5
PYDISTUTILSPKG= yes

do-test:
	( cd ${WKSRC} && ${PYTHONBIN} jsontest.py )

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
