# $NetBSD: Makefile,v 1.5 2012/10/06 17:13:23 asau Exp $
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

WRKSRC=		${WRKDIR}/${EGG_NAME}

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
