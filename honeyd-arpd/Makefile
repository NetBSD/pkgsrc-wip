# $NetBSD: Makefile,v 1.1.1.1 2003/04/07 10:11:55 adrian_p Exp $
#

DISTNAME=	arpd-0.2
PKGNAME=	honeyd-arpd-0.2
WRKSRC=		${WRKDIR}/arpd
CATEGORIES=	security net
MASTER_SITES=	http://niels.xtdnet.nl/honeyd/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://niels.xtdnet.nl/honeyd/index.php
COMMENT=	arp daemon for honeyd

DEPENDS+=	libevent-[0-9]*:../../devel/libevent
DEPENDS+=	libdnet-[0-9]*:../../net/libdnet

USE_PKGINSTALL= YES
RCD_SCRIPTS=	arpd

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
