# $NetBSD$

DISTNAME=	dropbox-3.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
GIT_REPO=	git://github.com/dropbox/dropbox-sdk-python.git

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/dropbox-sdk-python
COMMENT=	Python SDK for the Dropbox API v2
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
