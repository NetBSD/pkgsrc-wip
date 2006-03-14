# $NetBSD: Makefile,v 1.7 2006/03/14 01:28:08 jlamwww Exp $

DISTNAME=		pcsc-lite-1.2.9-beta10
PKGNAME=		${DISTNAME:S/-beta/b/}
CATEGORIES=		security
MASTER_SITES=		http://alioth.debian.org/download.php/1426/

MAINTAINER=		evaldo@gardenali.biz
HOMEPAGE=		http://www.linuxnet.com/
COMMENT=		PC/SC Architecture support for Smart Cards

GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
USE_TOOLS+=             automake gmake

.include "options.mk"

RCD_SCRIPTS=		pcscd
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-confdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--enable-ipcdir=${VARBASE}/pcsc-lite
CONFIGURE_ARGS+=	--enable-usbdropdir=${PREFIX}/lib/pcsc-lite/drivers
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers

EGDIR=			${PREFIX}/share/examples/pcsc-lite
CONF_FILES+=		${EGDIR}/reader.conf ${PKG_SYSCONFDIR}/reader.conf

pre-configure:
	cd ${WRKSRC} &&				\
	aclocal -I ./m4 &&			\
	autoheader &&				\
	libtoolize --force &&			\
	automake --copy --add-missing &&	\
	autoconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
