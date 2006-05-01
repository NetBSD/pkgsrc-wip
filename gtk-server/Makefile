# $NetBSD: Makefile,v 1.2 2006/05/01 14:20:07 shattered Exp $
#

DISTNAME=		gtk-server-2.0.10
CATEGORIES=		wip x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk-server/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://gtk-server.sourceforge.net/
COMMENT=		Small tool to enable GUI access for shell scripts

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/libffi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
