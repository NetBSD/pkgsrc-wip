# $NetBSD: Makefile,v 1.2 2003/06/30 00:10:12 xtraeme Exp $
#

DISTNAME=	gnome-themes-extras-0.1
PKGNAME=	${DISTNAME:S/gnome/gnome2/}
CATEGORIES=	x11 gnome2
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-extras/0.1/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Extra themes for GNOME2

DEPENDS=		gnome2-dirs>=1.0:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
