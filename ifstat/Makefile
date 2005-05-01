# $NetBSD: Makefile,v 1.5 2005/05/01 17:34:12 yeled Exp $
#

DISTNAME=	ifstat-1.1
CATEGORIES=	net sysutils
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	charlie@rubberduck.com
HOMEPAGE=	http://gael.roualland.free.fr/ifstat/
COMMENT=	ifstat is a tool to report network interfaces bandwidth

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+= --with-route # NetBSD
CONFIGURE_ARGS+= --with-proc=no # breaks with =auto
CONFIGURE_ARGS+= --with-kstat=no # ditto, etc ..
CONFIGURE_ARGS+= --with-ifmib=no
CONFIGURE_ARGS+= --with-ifdata=no
CONFIGURE_ARGS+= --with-kvm=no
CONFIGURE_ARGS+= --with-dlpi=no
CONFIGURE_ARGS+= --with-win32=no
CONFIGURE_ARGS+= --with-snmp=no
CONFIGURE_ARGS+= --with-libcrypto=no
CONFIGURE_ARGS+= --enable-library=no


.include "../../mk/bsd.pkg.mk"

# TODO
# --with-snmp
