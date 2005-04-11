# $NetBSD: Makefile,v 1.8 2005/04/11 21:13:51 tvierling Exp $
#

DISTNAME=		libxml++-0.27.0
PKGREVISION=		1
CATEGORIES=		textproc devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=libxmlplusplus/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://libxmlplusplus.sourceforge.net/
COMMENT=		C++ wrapper for the libxml2 XML parser library

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libxml++-1.0.pc.in
GNU_CONFIGURE=		yes

CPPFLAGS+=		-I${BUILDLINK_PREFIX.libxml2}/include/libxml2

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
