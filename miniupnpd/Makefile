# $NetBSD: Makefile,v 1.1.1.1 2009/03/02 12:39:16 jkjuopperi Exp $
#

DISTNAME=		miniupnpd-20081009
CATEGORIES=		net
MASTER_SITES=		http://miniupnp.free.fr/files/download.php?file= \
			http://miniupnp.tuxfamily.org/files/download.php?file=

MAINTAINER=		jkj@kapsi.fi
HOMEPAGE=		http://miniupnp.free.fr/
COMMENT=		UPnP/NAT-PMP Internet Gateway Device Daemon
ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-*-* OpenBSD-*-* SunOS-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			share/examples/miniupnpd
CONF_FILES=		${EGDIR}/miniupnpd.conf ${PKG_SYSCONFDIR}/miniupnpd.conf

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./genconfig.sh

BUILD_TARGET=		miniupnpd genuuid

RCD_SCRIPTS+=		miniupnpd

INSTALLATION_DIRS=	sbin ${EGDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/miniupnpd ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/miniupnpd.conf ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_MAN} ${WRKSRC}/miniupnpd.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
