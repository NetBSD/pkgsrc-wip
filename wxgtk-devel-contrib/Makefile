# $NetBSD: Makefile,v 1.1.1.1 2004/03/26 18:40:54 marc Exp $

.include "../../wip/wxgtk-devel/Makefile.common"

PKGNAME=	${DISTNAME:S/wxGTK/wxGTK-contrib/}
COMMENT=	GTK-based implementation of the wxWidgets GUI library

BUILD_DIRS=	${WRKSRC}/contrib/src
INSTALL_DIRS=	${BUILD_DIRS}

.include "../../wip/wxgtk-devel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
