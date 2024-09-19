# $NetBSD: Makefile,v 1.19 2015/01/10 20:17:05 thomasklausner Exp $

DISTNAME=	GTK2-Galaxy
PKGNAME=	gtk2-engines-galaxy-0.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=teams/art.gnome.org/archive/themes/gtk2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://art.gnome.org/
COMMENT=	Another theme engine for GTK+ 2.x
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/galaxy-0.2
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-gtktest  --disable-gdk_pixbuftest

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
