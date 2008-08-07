# $NetBSD: Makefile,v 1.10 2008/08/07 18:31:23 htepper Exp $

DISTNAME=		openct-0.6.15
CATEGORIES=		security
MASTER_SITES=		http://www.opensc-project.org/files/openct/

MAINTAINER=		hasso@estpak.ee
HOMEPAGE=		http://www.opensc-project.org/openct/
COMMENT=		Smart Card Reader drivers and middleware

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config

.include "options.mk"

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/openct
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
RCD_SCRIPTS=		openct
MAKE_DIRS+=		${VARBASE}/openct
MAKE_DIRS+=		${VARBASE}/openct/run
MAKE_DIRS+=		${VARBASE}/openct/run/openct
EGDIR=			${PREFIX}/share/examples/openct
CONF_FILES+=		${EGDIR}/openct.conf ${PKG_SYSCONFDIR}/openct.conf

INSTALLATION_DIRS=	${EGDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/openct.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${DESTDIR}${EGDIR}

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
