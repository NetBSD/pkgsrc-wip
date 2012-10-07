# $NetBSD: Makefile,v 1.5 2012/10/07 17:17:45 asau Exp $

DISTVERS=	0.3.4
DISTNAME=	TracAuthOpenId-${DISTVERS}
PKGNAME=	trac-plugins-AuthOpenId-${DISTVERS}
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/T/TracAuthOpenId/

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.sandbox.lt/auth/wiki/AuthOpenIdPlugin
COMMENT=	This plugins allows to login to Trac using OpenID
LICENSE=	modified-bsd

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-openid>=2.2.4:../../security/py-openid

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
