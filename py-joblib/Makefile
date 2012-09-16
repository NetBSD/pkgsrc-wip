# $NetBSD: Makefile,v 1.4 2012/09/16 09:16:53 noud4 Exp $
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

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/joblib-0.6.4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X= yes
PYTHON_VERSIONS_ACCEPTED= 25 26 27

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
