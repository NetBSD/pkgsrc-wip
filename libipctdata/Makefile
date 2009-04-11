# $NetBSD: Makefile,v 1.1.1.1 2009/04/11 12:50:04 jihbed Exp $
#

DISTNAME=	libiptcdata-1.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libiptcdata/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://libiptcdata.sourceforge.net/
COMMENT=	Library to parse IPTC metadata

PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_PORTABILITY_SKIP+=	configure

GNU_CONFIGURE=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config intltool gettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES+=	c c++


PKGCONFIG_OVERRIDE+=	libiptcdata/libiptcdata.pc.in

CONFIGURE_ARGS+=		 --disable-python

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
