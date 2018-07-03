# $NetBSD: Makefile,v 1.4 2013/06/19 14:12:22 noud4 Exp $

DISTNAME=	loggly-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/loggly/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/EA2D/loggly-python
COMMENT=	Python interface to Loggly
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-simplejson>=2.6.1:../../converters/py-simplejson

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # as of 0.1.2 (uses urllib2)

USE_LANGUAGES=	# none

post-extract:
	${MV} ${WRKSRC}/scripts/loggly-add-device ${WRKSRC}/scripts/loggly-add-device${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/loggly-create-input ${WRKSRC}/scripts/loggly-create-input${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/loggly-delete-input ${WRKSRC}/scripts/loggly-delete-input${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/loggly-describe-input ${WRKSRC}/scripts/loggly-describe-input${PYVERSSUFFIX}
	${MV} ${WRKSRC}/scripts/loggly-remove-device ${WRKSRC}/scripts/loggly-remove-device${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
