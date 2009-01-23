# $NetBSD: Makefile,v 1.25 2009/01/23 01:34:45 rsmarples Exp $
#

DISTNAME=		dhcpcd-4.99.11
CATEGORIES=		net
MASTER_SITES=		ftp://roy.marples.name/pub/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/projects/dhcpcd/
COMMENT=		RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

RCD_SCRIPTS+=		dhcpcd

# Install the ntp hook script by default
MAKE_ENV+=		HOOKSCRIPTS=50-ntp.conf

.include "../../mk/bsd.pkg.mk"
