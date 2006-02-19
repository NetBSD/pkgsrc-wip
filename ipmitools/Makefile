# $NetBSD: Makefile,v 1.2 2006/02/19 23:44:09 mreriksson Exp $
#

DISTNAME=		ipmitool-1.8.6
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ipmitool/}

MAINTAINER=		ola@mrEriksson.net
HOMEPAGE=		http://voxel.dl.sourceforge.net/sourceforge/ipmitool/
COMMENT=		Provides command-line interface to IPMI-enabled devices

CONFIGURE_ARGS+=	--enable-intf-imb=no

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
