# $NetBSD: Makefile,v 1.1.1.1 2011/03/20 23:33:48 jihbed Exp $
#

DISTNAME=	joblib-0.4.6.dev
EGG_NAME=	joblib-0.4.
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.dev//}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/j/joblib/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://packages.python.org/joblib/
COMMENT=	Lightweight pipelining: using Python functions as pipeline jobs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/joblib-0.4.6.dev
USE_LANGUAGES=	# none

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
