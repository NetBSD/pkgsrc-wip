# $NetBSD: Makefile,v 1.6 2012/10/07 11:54:46 asau Exp $
#

DISTNAME=	joblib-0.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
PKGREVISION=	2
MASTER_SITES=	http://pypi.python.org/packages/source/j/joblib/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://packages.python.org/joblib/
COMMENT=	Lightweight pipelining: using Python functions as pipeline jobs
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/joblib-0.6.4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X= yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
