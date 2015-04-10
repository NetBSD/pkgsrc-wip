# $NetBSD: Makefile,v 1.6 2015/04/10 19:38:52 krytarowski Exp $

USE_GTK_VERSION=3

.include "../../wip/libindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 symbols and convience functions for indicators
PKGNAME=	${DISTNAME:S/-/3-/}

INSTALL_DIRS=	libindicator

.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
