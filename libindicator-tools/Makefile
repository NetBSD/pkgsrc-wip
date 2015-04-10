# $NetBSD: Makefile,v 1.3 2015/04/10 19:23:37 krytarowski Exp $

USE_GTK_VERSION=2

.include "../../wip/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+2 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/-tools-/}

INSTALL_DIRS=	tools

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
