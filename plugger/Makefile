# $NetBSD: Makefile,v 1.12 2006/03/14 01:28:08 jlamwww Exp $
#

DISTNAME=	plugger-5.0
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/

MAINTAINER=	airhead@users.sourceforge.net
HOMEPAGE=	http://fredrik.hubbe.net/plugger.html
COMMENT=	Plugin for multimedia types in Mozilla, Netscape and Opera

REL_EGDIR=		share/examples/plugger
EGDIR=			${PREFIX}/${REL_EGDIR}
CONF_FILES=		${EGDIR}/pluggerrc ${PKG_SYSCONFDIR}/pluggerrc

PLIST_SUBST+=		EGDIR=${REL_EGDIR:Q}

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-${PKGVERSION} ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/plugger.so ${PREFIX}/lib/
	${INSTALL_MAN} ${WRKSRC}/plugger.7 ${PREFIX}/man/man7/
	${INSTALL_DATA} ${WRKSRC}/pluggerrc ${EGDIR}/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
