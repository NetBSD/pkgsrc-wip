# $NetBSD: Makefile,v 1.2 2012/01/30 06:32:14 noud4 Exp $
#

DISTNAME=	joblib-0.4.6.dev
EGG_NAME=	joblib-0.4.
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.dev//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/j/joblib/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://packages.python.org/joblib/
COMMENT=	Lightweight pipelining: using Python functions as pipeline jobs
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/joblib-0.4.6.dev
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
