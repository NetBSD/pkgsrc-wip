# $NetBSD: Makefile,v 1.6 2012/11/14 00:16:08 othyro Exp $
#

DISTNAME=		gtk-server-2.0.10
PKGREVISION=		1
CATEGORIES=		devel x11
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
