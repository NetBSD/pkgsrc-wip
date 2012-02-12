# $NetBSD: Makefile,v 1.4 2012/02/12 19:58:29 noud4 Exp $
#

DISTNAME=	mwavepy-1.0
EGG_NAME=	${DISTNAME}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://mwavepy.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/mwavepy/
COMMENT=	Python datatypes and functions for microwave engineering
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.7.0:../../math/py-scipy

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 26 25

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../graphics/py-matplotlib/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
