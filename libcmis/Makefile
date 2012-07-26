# $NetBSD: Makefile,v 1.1 2012/07/26 20:47:09 ftigeot Exp $

DISTNAME=	libcmis-0.2.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcmis/}

MAINTAINER=	ftigeot@wolfpond.org
HOMEPAGE=	http://sourceforge.net/projects/libcmis/
COMMENT=	Client library for the CMIS interface
LICENSE=	gnu-lgpl-v2.1 OR mpl-1.1 OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-curl=${BUILDLINK_PREFIX.curl}
CONFIGURE_ARGS+=	--without-man
PKGCONFIG_OVERRIDE=	libcmis.pc.in

.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
