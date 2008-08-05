# $NetBSD: Makefile,v 1.1.1.1 2008/08/05 22:59:31 jkuittinen Exp $
#

DISTNAME=	Beaker-0.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
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
