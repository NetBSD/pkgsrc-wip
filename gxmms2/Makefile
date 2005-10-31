# $NetBSD: Makefile,v 1.2 2005/10/31 09:07:00 leonardschmidt Exp $
#

DISTNAME=	gxmms2-0.5.1
CATEGORIES=	audio
MASTER_SITES=	http://wejp.homelinux.org/wejp/xmms2/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wejp.homelinux.org/wejp/xmms2/
COMMENT=	Graphical GTK+2-based XMMS2 client

NO_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../wip/xmms2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
