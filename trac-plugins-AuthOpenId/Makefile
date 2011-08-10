# $NetBSD: Makefile,v 1.3 2011/08/10 13:41:34 rsmarples Exp $

DISTVERS=	0.3.4
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
