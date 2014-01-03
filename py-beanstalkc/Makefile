# $NetBSD: Makefile,v 1.1 2014/01/03 05:42:05 othyro Exp $

DISTNAME=	beanstalkc-0.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	https://pypi.python.org/packages/source/b/beanstalkc/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/earl/beanstalkc
COMMENT=	Simple beanstalkd client library for Python
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	beanstalkc.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
