# $NetBSD: Makefile,v 1.13 2004/03/21 11:36:55 marc Exp $

DISTNAME=	libfwbuilder-1.0.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.fwbuilder.org/
COMMENT=	Firewall configuration and management tool

USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
GCC_REQD=	2.95.3
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-openssl-prefix=${BUILDLINK_PREFIX.openssl}

.if defined(FWBUILDER_USE_BIND) && !empty(FWBUILDER_USE_BIND:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-lwres
.include "../../net/bind9/buildlink2.mk"
.else
.include "../../security/openssl/buildlink2.mk"
.endif
BUILD_DEFS+=	FWBUILDER_USE_BIND

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../devel/glib/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
