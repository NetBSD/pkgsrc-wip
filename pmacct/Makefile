# $NetBSD: Makefile,v 1.3 2015/02/22 23:47:58 mbowie Exp $
#

DISTNAME=	pmacct-1.5.1
CATEGORIES=	net
MASTER_SITES=	http://www.pmacct.net/

MAINTAINER=	mbowie@rocketspace.com
HOMEPAGE=	http://www.pmacct.net/
COMMENT=	Tools to measure account, classify, aggregate and export IP traffic
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

EGDIR=	${PREFIX}/share/examples/pmacct
DOCDIR=	${PREFIX}/share/doc/pmacct

RCD_SCRIPTS=		nfacctd pmacctd sfacctd uacctd
PKG_SYSCONFSUBDIR=	pmacct

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${EGDIR}/sql

MESSAGE_SUBST+=		EGDIR=${EGDIR}
MESSAGE_SUBST+=		DOCDIR=${DOCDIR}

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.* ${DESTDIR}${EGDIR};
	${INSTALL_DATA} ${WRKSRC}/sql/* ${DESTDIR}${EGDIR}/sql;

.include "../../mk/bsd.pkg.mk"
