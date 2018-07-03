# $NetBSD: Makefile,v 1.1 2015/09/06 21:22:05 jihbed Exp $

DISTNAME=	python-premailer-0.5.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-premailer/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/ralphbean/python-premailer
COMMENT=	Prepare HTML for email embedd CSS to inline
#LICENSE=	# TODO: (see mk/license.mk)

DEPENDS+=	${PYPKGPREFIX}-cssutils>=1.0:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup>=3.2.1:../../www/py-beautifulsoup

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # use py-beautifulsoup4 for python-3.x

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
