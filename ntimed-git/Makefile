# $NetBSD: Makefile,v 1.2 2015/01/09 11:15:11 thomasklausner Exp $

DISTNAME=		ntimed-0.0
CATEGORIES=		time net
MASTER_SITES=		https://github.com/bsdphk/Ntimed

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/bsdphk/Ntimed
COMMENT=		Network Time Synchronization

GIT_REPOSITORIES=	Ntimed
GIT_REPO.Ntimed=	git://github.com/bsdphk/Ntimed.git

WRKSRC=			${WRKDIR}/Ntimed
GNU_CONFIGURE=		yes
# build problems with BSD make, see
# https://github.com/bsdphk/Ntimed/issues/25
USE_TOOLS+=		gmake

REPLACE_PYTHON+=		plotgen.py
#PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # as of 20150109

INSTALLATION_DIRS+=	sbin share/doc/ntimed

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntimed-client ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${PREFIX}/share/doc/ntimed/
	${INSTALL_DATA} ${WRKSRC}/plotgen.py ${DESTDIR}${PREFIX}/share/doc/ntimed/

.include "../../lang/python/application.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
