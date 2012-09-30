# $NetBSD: Makefile,v 1.4 2012/09/30 05:44:15 asau Exp $
#

DISTNAME=		ipmitool-1.8.6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ipmitool/}

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://ipmitool.sourceforge.net/
COMMENT=		Provides command-line interface to IPMI-enabled devices

PKG_DESTDIR_SUPPORT=	none

CONFIGURE_ARGS+=	--enable-intf-imb=no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
