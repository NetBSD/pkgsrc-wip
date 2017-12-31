# $NetBSD$

DISTNAME=	pybitbucket-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pybitbucket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/atlassian/python-bitbucket
COMMENT=	Python wrapper for the Bitbucket API
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-future>=0.16:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=2.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.7:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.12:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-simplejson>=3.10:../../converters/py-simplejson
DEPENDS+=	${PYPKGPREFIX}-six>=1.10:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=0.6:../../textproc/py-uritemplate
DEPENDS+=	${PYPKGPREFIX}-voluptuous>=0.9:../../wip/py-voluptuous

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
.endif

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/pybitbucket_cli ${DESTDIR}${PREFIX}/bin/pybitbucket_cli-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
