# $NetBSD: Makefile,v 1.1.1.1 2003/05/12 20:33:17 marc Exp $
#

DISTNAME=		libfwbuilder-0.10.13
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fwbuilder/}

MAINTAINER=		marc@informatik.uni-bremen.de
HOMEPAGE=		http://www.fwbuilder.org/
COMMENT=		firewall configuration and management tool

USE_CXX=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CONFIGURE_ARGS+=	--with-lwres
CONFIGURE_ARGS+=	--with-openssl-prefix=${BUILDLINK_PREFIX.openssl}

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/libtoolize --force --copy
	cd ${WRKSRC} && ${ACLOCAL}
	cd ${WRKSRC} && ${AUTOCONF}

.include "../../devel/glib/buildlink2.mk"
.include "../../lang/gcc/buildlink2.mk"
.include "../../net/ucd-snmp/buildlink2.mk"
.include "../../net/bind9/buildlink2.mk"
.include "../../textproc/libxslt/buildlink2.mk"
.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
