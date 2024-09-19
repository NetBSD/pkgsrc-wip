# $NetBSD: Makefile,v 1.7 2015/04/13 23:33:19 othyro Exp $

DISTNAME=	pycscope-1.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycscope/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/pycscope/
COMMENT=	Generates a cscope index of Python source trees
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	pycscope/__init__.py

INSTALLATION_DIRS=	share/doc/py-cscope

post-install:
	${INSTALL_DATA} ${WRKSRC}/README  \
		${DESTDIR}${PREFIX}/share/doc/py-cscope

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
