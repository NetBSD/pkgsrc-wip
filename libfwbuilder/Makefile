# $NetBSD: Makefile,v 1.7 2003/09/24 21:54:14 tvierling Exp $
#

DISTNAME=		libfwbuilder-1.0.0
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.fwbuilder.org/
COMMENT=		Firewall configuration and management tool

USE_CXX=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-openssl-prefix=${BUILDLINK_PREFIX.openssl}

.if defined(FWBUILDER_USE_BIND) && !empty(FWBUILDER_USE_BIND:M[yY][eE][sS])
CONFIGURE_ARGS+=	--with-lwres
.include "../../net/bind9/buildlink2.mk"
.else
.include "../../security/openssl/buildlink2.mk"
.endif

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../devel/glib/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
