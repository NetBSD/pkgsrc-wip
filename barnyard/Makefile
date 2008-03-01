# $NetBSD: Makefile,v 1.14 2008/03/01 14:46:44 asau Exp $

DISTNAME=	barnyard-0.2.0
CATEGORIES=	net
MASTER_SITES=	http://www.snort.org/dl/barnyard/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.snort.org/
COMMENT=	Fast output system for snort

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

PKG_SYSCONFSUBDIR=	snort

CONF_FILES=	${EGDIR}/barnyard.conf ${PKG_SYSCONFDIR}/barnyard.conf

EGDIR=		${PREFIX}/share/examples/barnyard

.include "options.mk"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/barnyard
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}

	${INSTALL_SCRIPT} ${WRKSRC}/src/barnyard ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/docs/FAQ ${DESTDIR}${PREFIX}/share/doc/barnyard/FAQ
	${INSTALL_DATA} ${WRKSRC}/docs/USAGE ${DESTDIR}${PREFIX}/share/doc/barnyard/USAGE
	${INSTALL_DATA} ${WRKSRC}/etc/barnyard.conf ${DESTDIR}${EGDIR}/barnyard.conf

.include "../../mk/bsd.pkg.mk"
