# $NetBSD: Makefile,v 1.3 2004/02/17 02:56:03 blef Exp $
#

DISTNAME=		libxml++-0.27.0
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libxmlplusplus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://libxmlplusplus.sourceforge.net/
COMMENT=		C++ wrapper for the libxml2 XML parser library

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libxml++-1.0.pc.in
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
