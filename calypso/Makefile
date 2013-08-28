# $NetBSD: Makefile,v 1.9 2013/08/28 06:47:25 thomasklausner Exp $

DISTNAME=	calypso-1.1
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject
DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

GIT_REPOSITORIES=	calypso
GIT_REPO.calypso=	git://keithp.com/git/calypso.git

WRKSRC=		${WRKDIR}/calypso

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCLUDE_3X=	yes

INSTALLATION_DIRS=	share/examples/calypso

REPLACE_PYTHON=	calypso.py
EGG_NAME=	${DISTNAME:S/c/C/}

post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
