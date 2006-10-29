# $NetBSD: Makefile,v 1.9 2006/10/29 08:32:53 shattered Exp $

DISTNAME=		pcsc-lite-1.3.1
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/1565/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.linuxnet.com/
COMMENT=		PC/SC Architecture support for Smart Cards

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_TOOLS+=		gmake

.include "options.mk"

RCD_SCRIPTS=		pcscd
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-confdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-ipcdir=${VARBASE}/pcsc-lite
CONFIGURE_ARGS+=	--enable-usbdropdir=${PREFIX}/lib/pcsc-lite/drivers
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers

EGDIR=			${PREFIX}/share/examples/pcsc-lite
CONF_FILES+=		${EGDIR}/reader.conf ${PKG_SYSCONFDIR}/reader.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
