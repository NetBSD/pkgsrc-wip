# $NetBSD: Makefile,v 1.3 2012/05/11 12:47:07 noud4 Exp $
#

DISTNAME=	Beaker-1.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/B/Beaker/

MAINTAINER=	jkuittinen@users.sourceforge.net
HOMEPAGE=	http://beaker.groovie.org/
COMMENT=	Beaker is a web session and general caching library

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${EGG_NAME}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
