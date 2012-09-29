# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=		gtk-server-2.0.10
PKGREVISION=		1
CATEGORIES=		wip x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk-server/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gtk-server.org/
COMMENT=		Small tool to enable GUI access for shell scripts

PKG_DESTDIR_SUPPORT=	none

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/libffi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
