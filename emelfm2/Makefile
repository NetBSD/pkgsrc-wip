# $NetBSD: Makefile,v 1.2 2005/07/27 16:00:58 leonardschmidt Exp $
#

DISTNAME=	emelfm2-tom-20050726
PKGNAME=	${DISTNAME:S/-tom-/-/}
CATEGORIES=	sysutils
MASTER_SITES=	http://emelfm2.org/rel/pre/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://emelfm2.org/
COMMENT=	Fast two-pane file manager using GTK2

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		xdg-1.1
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
