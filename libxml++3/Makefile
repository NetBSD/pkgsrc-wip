# $NetBSD$

DISTNAME=	libxml++-3.0.1
PKGNAME=	${DISTNAME:S/-/3-/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libxml++/${PKGVERSION:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libxmlplusplus.sourceforge.net/
COMMENT=	C++ wrapper for the libxml XML parser library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config gmake perl
PKGCONFIG_OVERRIDE+=	${WRKSRC}/libxml++-.pc.in
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	MMDOCTOOLDIR=${PREFIX}/share/glibmm-2.4/doctool

.include "../../devel/glibmm/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
