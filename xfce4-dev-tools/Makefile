# $NetBSD: Makefile,v 1.12 2012/10/07 20:11:09 asau Exp $

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
