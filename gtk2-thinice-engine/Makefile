# $NetBSD: Makefile,v 1.3 2003/06/30 00:10:12 xtraeme Exp $
#

DISTNAME=	gtk-thinice-engine-2.0.2
PKGNAME=	${DISTNAME:S/gtk/gtk2/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtk-thinice-engine/2.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Simple, clean theme engine

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=    ${WRKSRC}/gtk-thinice-engine-2.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
