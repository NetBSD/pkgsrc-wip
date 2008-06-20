# $NetBSD: Makefile,v 1.9 2008/06/20 08:34:36 rsmarples Exp $
#

DISTNAME=		dhcpcd-4.0.0-beta7
PKGNAME=		dhcpcd-4.0.0beta7
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
