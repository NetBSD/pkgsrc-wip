# $NetBSD: Makefile,v 1.10 2005/06/12 23:51:25 kristerw Exp $
#

DISTNAME=	plugger-5.0
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	Plugin for multimedia types in Mozilla, Netscape and Opera

USE_PKGINSTALL=		YES

REL_EGDIR=		share/examples/plugger
EGDIR=			${PREFIX}/${REL_EGDIR}
CONF_FILES=		${EGDIR}/pluggerrc ${PKG_SYSCONFDIR}/pluggerrc

PLIST_SUBST+=		EGDIR=${REL_EGDIR}

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PKGVERSION} ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/plugger.so ${PREFIX}/lib/
	${INSTALL_MAN} ${WRKSRC}/plugger.7 ${PREFIX}/man/man7/
	${INSTALL_DATA} ${WRKSRC}/pluggerrc ${EGDIR}/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
