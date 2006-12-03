# $NetBSD: Makefile,v 1.2 2006/12/03 22:44:30 bartoszkuzma Exp $
#

DISTNAME=		gdhcpd-0.3.1
CATEGORIES=		sysutils
MASTER_SITES=		http://mange.dynalias.org/linux/gdhcpd/

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://mange.dynalias.org/linux/gdhcpd/
COMMENT=		Easy to use gtk+ frontend for isc-dhcpd

DHCPD_BINARY?=		/usr/sbin/dhcpd
DHCPD_CONF?=		/etc/dhcpd.conf
LEASE_FILE?=		/var/db/dhcpd.leases

BUILD_DEFS+=		DHCPD_BINARY
BUILD_DEFS+=		DHCPD_CONF
BUILD_DEFS+=		LEASE_FILE

USE_DIRS+=		xgd-1.1
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	DHCPD_BINARY=${DHCPD_BINARY:Q}
CONFIGURE_ARGS+=	DHCPD_CONF=${DHCPD_CONF:Q}
CONFIGURE_ARGS+=	LEASE_FILE=${LEASE_FILE:Q}
CONFIGURE_ARGS+=	--sbindir=${PREFIX}/sbin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
