# $NetBSD$

GITHUB_PROJECT=	sentry-python
DISTNAME=	sentry-sdk-${GITHUB_RELEASE}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=getsentry/}
GITHUB_RELEASE=	0.19.4
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://github.com/getsentry/sentry-python/
COMMENT=	The new Python SDK for Sentry.io
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-certifi>=0:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.9:../../www/py-urllib3

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
