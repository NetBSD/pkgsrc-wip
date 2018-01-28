# $NetBSD: Makefile,v 1.9 2012/10/03 18:15:32 asau Exp $

DISTNAME=		netkit-base-0.17
PKGREVISION=		1
CATEGORIES=		net
# sunsite has older 0.16 version
MASTER_SITES=		ftp://ftp.uk.linux.org/pub/linux/Networking/netkit/

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://www.hcs.harvard.edu/~dholland/computers/netkit.html
COMMENT=		The inetd super server and ping for Linux

ONLY_FOR_PLATFORM=	Linux-*-*


USE_TOOLS+=		gmake

MAKE_ENV+=		_PATH_INETDCONF=${PKG_SYSCONFDIR}

RCD_SCRIPTS=		inetd
CONF_FILES=		${PREFIX}/share/examples/${PKGBASE}/inetd.conf ${PKG_SYSCONFDIR}/inetd.conf

do-configure:
	cd ${WRKSRC} && \
	${SET_ENV} ${CONFIGURE_ENV} ./configure --prefix=${PREFIX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/${PKGBASE}/etc.sample
	${INSTALL_DATA} ${WRKSRC}/etc.sample/* ${PREFIX}/share/examples/${PKGBASE}/etc.sample/
	${INSTALL_DATA} ${FILESDIR}/inetd.conf ${PREFIX}/share/examples/${PKGBASE}/

.include "../../mk/bsd.pkg.mk"
