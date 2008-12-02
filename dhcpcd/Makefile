# $NetBSD: Makefile,v 1.23 2008/12/02 15:11:26 rsmarples Exp $
#

DISTNAME=		dhcpcd-4.0.7
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

# The RC script needs some loving
RCD_SCRIPTS+=		dhcpcd

# Install the ntp hook script by default
MAKE_ENV+=		HOOKSCRIPTS=50-ntp.conf

.include "../../mk/bsd.pkg.mk"
