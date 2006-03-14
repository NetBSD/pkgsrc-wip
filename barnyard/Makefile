# $NetBSD: Makefile,v 1.12 2006/03/14 01:27:58 jlamwww Exp $

DISTNAME=	barnyard-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/dl/barnyard/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://www.snort.org/
COMMENT=	Fast output system for snort

GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	snort

CONF_FILES=	${EGDIR}/barnyard.conf ${PKG_SYSCONFDIR}/barnyard.conf

EGDIR=		${PREFIX}/share/examples/barnyard

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/barnyard
	${INSTALL_DATA_DIR} ${EGDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/barnyard ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${PREFIX}/share/doc/barnyard/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE ${PREFIX}/share/doc/barnyard/USAGE
	${INSTALL_DATA} ${WRKSRC}/etc/barnyard.conf ${EGDIR}/barnyard.conf

.include "../../mk/bsd.pkg.mk"
