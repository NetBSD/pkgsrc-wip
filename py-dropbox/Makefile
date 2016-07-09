# $NetBSD$

DISTNAME=	dropbox-3.38
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dropbox/dropbox-sdk-python
COMMENT=	Python SDK for the Dropbox API v2
LICENSE=	mit

GIT_REPOSITORIES=		dropbox-sdk-python
GIT_REPO.dropbox-sdk-python=	git://github.com/dropbox/dropbox-sdk-python.git

DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

WRKSRC=		${WRKDIR}/dropbox-sdk-python

.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
