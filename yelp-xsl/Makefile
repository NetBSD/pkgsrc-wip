# $NetBSD: Makefile,v 1.6 2011/08/06 06:57:24 obache Exp $
#

DISTNAME=	yelp-xsl-3.0.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/yelp-xsl/3.0/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://www.gnome.org/
COMMENT=	XSL stylesheets for Yelp help browser
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool

PKGCONFIG_OVERRIDE+=	yelp-xsl.pc.in

BUILDLINK_API_DEPENDS.libxml2+=	libxml2>=2.6.12
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
