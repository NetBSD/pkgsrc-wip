# $NetBSD: Makefile,v 1.1 2015/01/26 09:25:42 thomasklausner Exp $

DISTNAME=	calypso-1.3
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server (git version)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

GIT_REPOSITORIES=	calypso
GIT_REPO.calypso=	git://keithp.com/git/calypso.git

WRKSRC=		${WRKDIR}/calypso

PYDISTUTILSPKG=			yes

INSTALLATION_DIRS=	share/examples/calypso

REPLACE_PYTHON=	calypso.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-vobject

post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
