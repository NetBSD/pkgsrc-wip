# $NetBSD: Makefile,v 1.9 2008/05/06 13:21:23 htepper Exp $

DISTNAME=		openct-0.6.14
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/openct/

MAINTAINER=		hasso@estpak.ee
HOMEPAGE=		http://www.opensc-project.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

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
