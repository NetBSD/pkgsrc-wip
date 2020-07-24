# $NetBSD: Makefile,v 1.8 2015/08/04 20:04:14 thomasklausner Exp $

# upstream does not support 1.2/1.4
# https://github.com/trac-hacks/authopenid-plugin/issues/32
# to be deleted 2020-08-06 if no response

DISTVERS=	0.3.4
DISTNAME=	TracAuthOpenId-${DISTVERS}
PKGNAME=	trac-plugins-AuthOpenId-${DISTVERS}
PKGREVISION=	1
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=T/TracAuthOpenId/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/trac-hacks/authopenid-plugin
COMMENT=	This plugins allows to login to Trac using OpenID
LICENSE=	modified-bsd

DEPENDS+=	trac>=0.11:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-openid>=2.2.4:../../security/py-openid

PYTHON_VERSIONS_ACCEPTED=	27 # py-openid

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
