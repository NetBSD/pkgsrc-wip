# $NetBSD: Makefile,v 1.5 2004/05/09 02:39:40 minskim Exp $
#

DISTNAME=		libxml++-0.27.0
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libxmlplusplus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://libxmlplusplus.sourceforge.net/
COMMENT=		C++ wrapper for the libxml2 XML parser library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libxml++-1.0.pc.in
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
