# $NetBSD: Makefile,v 1.4 2008/03/07 11:06:01 rsmarples Exp $
#

DISTNAME=	dhcpcd-3.2.3
CATEGORIES=	net
MASTER_SITES=	http://roy.marples.name/dhcpcd/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	roy@marples.name
HOMEPAGE=	http://roy.marples.name/dhcpcd/
COMMENT=	RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c99

MAKE_ENV+=	MANDIR=${PREFIX}/${PKGMANDIR}/man

RCD_SCRIPTS+=	dhcpcd

.include "../../mk/bsd.pkg.mk"
