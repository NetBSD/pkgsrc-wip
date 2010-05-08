# $NetBSD: Makefile,v 1.1.1.1 2010/05/08 18:37:58 jihbed Exp $
#

DISTNAME=	yelp-xsl-2.31.1
CATEGORIES=	misc textproc
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/yelp-xsl/2.31/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.gnome.org/
COMMENT=	XSLT stylesheets that were once distributed with Yelp
LICENSE=	gnu-gpl-v2 OR gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	yelp-xsl.pc.in

CONFIGURE_ARGS+=	--enable-doc

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.2
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
