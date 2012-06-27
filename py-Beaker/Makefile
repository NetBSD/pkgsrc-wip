# $NetBSD: Makefile,v 1.4 2012/06/27 14:42:29 uccwen Exp $
#

DISTNAME=	Beaker-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/B/Beaker/

MAINTAINER=	jkuittinen@users.sourceforge.net
HOMEPAGE=	http://beaker.groovie.org/
COMMENT=	Beaker is a web session and general caching library

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${EGG_NAME}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
