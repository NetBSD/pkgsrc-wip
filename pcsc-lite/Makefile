# $NetBSD: Makefile,v 1.3 2005/07/23 22:07:04 udontknow Exp $

DISTNAME=	pcsc-lite-1.2.9-beta7
PKGNAME=	pcsc-lite-1.2.9
CATEGORIES=	security
MASTER_SITES=	http://alioth.debian.org/download.php/975/

MAINTAINER=	evaldo@gardenali.biz
HOMEPAGE=	http://www.linuxnet.com/
COMMENT=	PC/SC Architecture support for Smart Cards

GNU_CONFIGURE=          YES
USE_PKGINSTALL=		YES
USE_LIBTOOL=            YES
USE_TOOLS+=             automake gmake

.include "options.mk"

RCD_SCRIPTS=		pcscd
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-ipcdir=${VARBASE}/pcsc-lite
CONFIGURE_ARGS+=	--enable-usbdropdir=${PREFIX}/lib/pcsc-lite/drivers
MAKE_DIRS+=		${VARBASE}/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite
MAKE_DIRS+=		${PREFIX}/lib/pcsc-lite/drivers

EGDIR=			${PREFIX}/share/examples/pcsc-lite
CONF_FILES+=		${EGDIR}/reader.conf ${PKG_SYSCONFDIR}/reader.conf

pre-configure:
	cd ${WRKSRC} && \
	aclocal -I ./m4 && \
	autoheader && \
	libtoolize --force && \
	automake --copy --add-missing && \
	autoconf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/reader.conf ${EGDIR}

.include "../../mk/bsd.pkg.mk"
