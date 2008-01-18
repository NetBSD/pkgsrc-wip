# $NetBSD: Makefile,v 1.1.1.1 2008/01/18 23:34:01 hoka_adam Exp $
#

DISTNAME=	dhcpcd-3.1.9
CATEGORIES=	net
MASTER_SITES=	http://roy.marples.name/dhcpcd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://roy.marples.name/dhcpcd/
COMMENT=	RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c99

MAKE_ENV+=	INFODIR=${PREFIX}/var/db
MAKE_ENV+=	MANPREFIX=${PREFIX}

RCD_SCRIPTS+=	dhcpcd

.include "../../mk/bsd.pkg.mk"
