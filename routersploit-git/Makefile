# $NetBSD: Makefile,v 1.4 2017/09/14 12:43:54 leot Exp $

DISTNAME=	routersploit-2.2.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=reverse-shell/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/reverse-shell/routersploit
COMMENT=	The Router Exploitation Framework
LICENSE=	modified-bsd

GIT_REPOSITORIES=	routersploit
GIT_REPO.routersploit=	git://github.com/reverse-shell/routersploit.git
WRKSRC=			${WRKDIR}/routersploit

DEPENDS+=	${PYPKGPREFIX}-requests>=2.9.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-paramiko>=1.16.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.1:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-snmp>=4.3.2:../../wip/py-snmp

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.2.1

post-extract:
	${CP} ${FILESDIR}/setup.py ${WRKSRC}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
