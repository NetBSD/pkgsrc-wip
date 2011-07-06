# $NetBSD: Makefile,v 1.1.1.1 2011/07/06 10:11:29 bubuchka Exp $
#

DISTNAME=	p4api
DISTFILES=	p4api.tgz
HOMEPAGE=	http://www.perforce.com/perforce/loadsupp.html
COMMENT=	Perforce SCM C/C++ API

PKG_DESTDIR_SUPPORT=	user-destdir

P4BINONLY=	yes

.include "../../wip/p4/Makefile.common"

INSTALLATION_DIRS=	include/p4
INSTALLATION_DIRS+=	lib/p4
INSTALLATION_DIRS+=	share/examples/p4

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/p4/* ${DESTDIR}${PREFIX}/include/p4
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/p4
	${INSTALL_DATA} ${WRKSRC}/sample/* ${DESTDIR}${PREFIX}/share/examples/p4

.include "../../mk/bsd.pkg.mk"
