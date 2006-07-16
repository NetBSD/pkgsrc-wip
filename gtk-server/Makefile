# $NetBSD: Makefile,v 1.3 2006/07/16 16:08:38 shattered Exp $
#

DISTNAME=		gtk-server-2.0.10
CATEGORIES=		wip x11 devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gtk-server/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.gtk-server.org/
COMMENT=		Small tool to enable GUI access for shell scripts

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/libffi/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
