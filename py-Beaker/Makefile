# $NetBSD: Makefile,v 1.6 2015/07/15 17:54:20 thomasklausner Exp $

DISTNAME=	Beaker-1.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
EGG_NAME=	${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=B/Beaker/}

MAINTAINER=	jkuittinen@users.sourceforge.net
HOMEPAGE=	http://beaker.groovie.org/
COMMENT=	Beaker is a web session and general caching library

LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${EGG_NAME}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
