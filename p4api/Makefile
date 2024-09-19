# $NetBSD: Makefile,v 1.3 2012/10/04 09:13:18 asau Exp $
#

DISTNAME=	p4api
DISTFILES=	p4api.tgz
HOMEPAGE=	http://www.perforce.com/product/components/apis
COMMENT=	Perforce SCM C/C++ API

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
