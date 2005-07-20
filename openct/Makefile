# $NetBSD: Makefile,v 1.2 2005/07/20 19:53:21 udontknow Exp $

DISTNAME=      		openct-0.6.5
CATEGORIES=     	security
MASTER_SITES= 		http://www.opensc.org/files/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE= 		http://www.opensc.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

GNU_CONFIGURE= 		YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=		YES
USE_TOOLS+= 		gmake

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/openct
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
EGDIR=			${PREFIX}/share/examples/openct
RCD_SCRIPTS=		openct
MAKE_DIRS+=		${VARBASE}/openct
MAKE_DIRS+=		${VARBASE}/openct/run
MAKE_DIRS+=		${VARBASE}/openct/run/openct
CONF_FILES+=		${EGDIR}/openct.conf ${PKG_SYSCONFDIR}/openct.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/openct.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
