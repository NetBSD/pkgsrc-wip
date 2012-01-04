# $NetBSD: Makefile,v 1.1.1.1 2012/01/04 17:55:50 thomasklausner Exp $

DISTNAME=	calypso-0.5
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://keithp.com/blogs/calypso/
COMMENT=	CardDAV/CalDAV server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject>=0.8.1c:../../textproc/py-vobject

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=	calypso
GIT_REPO.calypso=	git://keithp.com/git/calypso.git

WRKSRC=		${WRKDIR}/calypso

PYDISTUTILSPKG=			yes
PYTHON_VERSIONS_INCLUDE_3X=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	24 25

INSTALLATION_DIRS=	share/examples/calypso

REPLACE_PYTHON=	calypso.py

post-install:
	${INSTALL_DATA} ${WRKSRC}/config ${DESTDIR}${PREFIX}/share/examples/calypso/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
