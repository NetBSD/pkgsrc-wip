# $NetBSD: Makefile,v 1.16 2004/05/04 06:50:15 thomasklausner Exp $

DISTNAME=	libfwbuilder-1.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall configuration and management tool

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
GCC_REQD=	2.95.3
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-openssl-prefix=${BUILDLINK_PREFIX.openssl}

.if defined(FWBUILDER_USE_BIND) && !empty(FWBUILDER_USE_BIND:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-lwres
.include "../../net/bind9/buildlink3.mk"
.endif
BUILD_DEFS+=	FWBUILDER_USE_BIND

.include "../../devel/glib/buildlink3.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
