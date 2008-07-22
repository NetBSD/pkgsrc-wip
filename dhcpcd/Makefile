# $NetBSD: Makefile,v 1.12 2008/07/22 09:15:10 rsmarples Exp $
#

DISTNAME=		dhcpcd-4.0.0-rc1
PKGNAME=		dhcpcd-4.0.0rc1
CATEGORIES=		net
MASTER_SITES=		http://roy.marples.name/dhcpcd/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		roy@marples.name
HOMEPAGE=		http://roy.marples.name/dhcpcd/
COMMENT=		RFC2131 compliant DHCP client

PKG_DESTDIR_SUPPORT=	user-destdir
USE_LANGUAGES=		c99

EGDIR=			${PREFIX}/share/examples
MAKE_ENV+=		MANDIR=${PREFIX}/${PKGMANDIR}/man
INSTALL_MAKE_FLAGS+=	SYSCONFDIR=${EGDIR}

# Install the configuration file
CONF_FILES+=		${EGDIR}/dhcpcd.conf ${PKG_SYSCONFDIR}/dhcpcd.conf

# The RC script needs some loving
RCD_SCRIPTS+=		dhcpcd

# Install the ntp hook script by default
MAKE_ENV+=		HOOKSCRIPTS=50-ntp.conf

.include "../../mk/bsd.pkg.mk"
