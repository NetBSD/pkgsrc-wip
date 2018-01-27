# $NetBSD: Makefile,v 1.2 2015/02/18 08:09:25 thomasklausner Exp $

DISTNAME=	Gato-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	math graphics python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/Gato/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://gato.sf.net/
COMMENT=	Python-based toolbox to visualise algorithms on graphs
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 1.2.2
REPLACE_PYTHON+=		*.py

post-extract:
	${MV} ${WRKSRC}/scripts/Gato ${WRKSRC}/scripts/Gato${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/Gred ${WRKSRC}/scripts/Gred${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
