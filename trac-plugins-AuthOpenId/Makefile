# $NetBSD: Makefile,v 1.2 2009/07/21 14:14:44 rsmarples Exp $

DISTVERS=	0.2.1
DISTNAME=	TracAuthOpenId-${DISTVERS}
PKGNAME=	trac-plugins-AuthOpenId-${DISTVERS}
EGG_NAME=	${PKGNAME}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/T/TracAuthOpenId/

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.sandbox.lt/auth/wiki/AuthOpenIdPlugin
COMMENT=	This plugins allows to login to Trac using OpenID
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-openid>=2.2.4:../../security/py-openid

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
