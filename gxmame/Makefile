# $NetBSD: Makefile,v 1.1.1.1 2003/10/24 00:07:39 xtraeme Exp $
#

DISTNAME=	gxmame-0.33
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gxmame/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gxmame.sourceforge.net/
COMMENT=	Frontend for XMame using the GTK library

BUILD_USES_MSGFMT=	yes
DEPENDS=		gnome1-dirs>=1.0:../../misc/gnome1-dirs
DEPENDS+=		xmame-[0-9]*:../../emulators/xmame

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

CONFIGURE_ARGS+=	--disable-joystick

.include "../../converters/libiconv/buildlink2.mk"
.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
