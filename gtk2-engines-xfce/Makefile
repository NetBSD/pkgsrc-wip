# $NetBSD: Makefile,v 1.1.1.1 2003/04/24 16:52:42 bmeurer Exp $
#

DISTNAME=		gtk-xfce-engine-2.1.0
PKGNAME=		gtk2-engines-xfce-2.1.0
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.unix-ag.org/user/bmeurer/xfce4/pre4/

MAINTAINER=		benedikt.meurer@unix-ag.uni-siegen.de
HOMEPAGE=		http://www.xfce.org/
COMMENT=		Gtk2 themes that come with XFce4

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
