# $NetBSD: Makefile,v 1.2 2003/08/29 19:10:23 jmmv Exp $
#

DISTNAME=	openbox-3.0-alpha6
PKGNAME=	${DISTNAME:S/-alpha/alpha/}
CATEGORIES=	wm x11
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://icculus.org/openbox/
COMMENT=	Standards compliant, light-weight and extensible window manager.

BUILD_USES_MSGFMT=	YES
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
USE_X11=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
