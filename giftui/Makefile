# $NetBSD: Makefile,v 1.4 2004/05/07 01:57:55 xtraeme Exp $
#

DISTNAME=	giFTui-0.1.1
PKGNAME=	${DISTNAME:S/FT/ft/}
CATEGORIES=	net
MASTER_SITES=	http://giftui.tuxfamily.org/downloads/sources/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://giftui.tuxfamily.org/
COMMENT=	Graphical user interface to giFT using GTK+2

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_X11=		yes

.include "../../x11/gtk2/buildlink3.mk"
.include "../../wip/gift/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
