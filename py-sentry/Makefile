# $NetBSD: Makefile,v 1.1 2015/01/14 21:18:37 jihbed Exp $

DISTNAME=	sentry-7.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=s/sentry/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.getsentry.com
COMMENT=	Realtime logging and aggregation server
LICENSE=	modified-bsd

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

DEPENDS+=	${PYPKGPREFIX}-flake8-2.2.5>=:../../devel/py-flake8
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
