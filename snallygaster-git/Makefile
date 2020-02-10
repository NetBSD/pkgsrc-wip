# $NetBSD$

DISTNAME=	snallygaster-0.0.4
CATEGORIES=	security python
MASTER_SITES=	# none

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hannob/snallygaster
COMMENT=	Tool to scan for secret files on HTTP servers
LICENSE=	cc0-1.0-universal

GIT_REPOSITORIES=	snallygaster
GIT_REPO.snallygaster=	git://github.com/hannob/snallygaster.git
WRKSRC=			${WRKDIR}/snallygaster

DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-urllib3-[0-9]*:../../www/py-urllib3

USE_LANGUAGES=			# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
