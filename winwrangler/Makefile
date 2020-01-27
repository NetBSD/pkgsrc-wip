# $NetBSD: Makefile,v 1.7 2014/06/01 12:49:49 thomasklausner Exp $
#

DISTNAME=	winwrangler-0.2.1
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://launchpad.net/winwrangler/0.2/0.2.1/+download/

MAINTAINER=	pkgsrc-users@netbsd.org
HOMEPAGE=	https://launchpad.net/winwrangler/
COMMENT=	WinWrangler desktop daemon to manipulations window managers
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool perl pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/gtkhotkey/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
