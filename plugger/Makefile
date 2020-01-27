# $NetBSD: Makefile,v 1.16 2012/10/05 11:27:15 asau Exp $
#

DISTNAME=	plugger-5.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://fredrik.hubbe.net/plugger/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fredrik.hubbe.net/plugger.html
COMMENT=	Plugin for multimedia types in Mozilla, Netscape and Opera

REL_EGDIR=		share/examples/plugger
EGDIR=			${PREFIX}/${REL_EGDIR}
CONF_FILES=		${EGDIR}/pluggerrc ${PKG_SYSCONFDIR}/pluggerrc

PLIST_SUBST+=		EGDIR=${REL_EGDIR:Q}

INSTALLATION_DIRS=	bin lib ${PKGMANDIR}/man7

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-5.0 ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/plugger-controller ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/plugger.so ${DESTDIR}${PREFIX}/lib/
	${INSTALL_MAN} ${WRKSRC}/plugger.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/
	${INSTALL_DATA} ${WRKSRC}/pluggerrc ${DESTDIR}${EGDIR}/

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
