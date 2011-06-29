# $NetBSD: Makefile,v 1.11 2011/06/29 09:37:23 reinoudz70 Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	xfce4-dev-tools-${XFCE4_VERSION}
CATEGORIES=	devel
COMMENT=	Xfce development tools
LICENSE=	gnu-gpl-v2

XFCE4_PROJECT=  xfce4-dev-tools
XFCE4_BRANCH=   4.8

GNU_CONFIGURE=	yes

USE_TOOLS+=	bash:run
REPLACE_BASH+=	scripts/xdt-commit

MAKE_DIRS+=	${PREFIX}/share/xfce4

.include "../../mk/bsd.pkg.mk"
