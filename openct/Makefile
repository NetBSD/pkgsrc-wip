# $NetBSD: Makefile,v 1.7 2006/03/24 21:42:25 udontknow Exp $

DISTNAME=      		openct-0.6.6
CATEGORIES=     	security
MASTER_SITES= 		http://www.opensc-project.org/files/openct/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE= 		http://www.opensc-project.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

GNU_CONFIGURE= 		YES
USE_LIBTOOL=		YES
USE_TOOLS+= 		gmake pkg-config

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/openct
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
EGDIR=			${PREFIX}/share/examples/openct
RCD_SCRIPTS=		openct
MAKE_DIRS+=		${VARBASE}/openct
MAKE_DIRS+=		${VARBASE}/openct/run
MAKE_DIRS+=		${VARBASE}/openct/run/openct
CONF_FILES+=		${EGDIR}/openct.conf ${PKG_SYSCONFDIR}/openct.conf

PLIST_SRC+=		${PKGDIR}/PLIST.common

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/openct.conf ${EGDIR}
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
