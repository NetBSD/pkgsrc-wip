# $NetBSD: Makefile,v 1.3 2004/05/07 01:58:10 xtraeme Exp $
#

DISTNAME=	matchbox-window-manager-0.8
CATEGORIES=	wm
MASTER_SITES=	http://matchbox.handhelds.org/sources/matchbox-window-manager/0.8/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://matchbox.handhelds.org/sources/matchbox-window-manager/0.8/
COMMENT=	The Matchbox window manager

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

GCONF2_SCHEMAS+=	matchbox.schemas

CONFIGURE_ARGS+=	--enable-gconf
CONFIGURE_ARGS+=	--enable-expat
CONFIGURE_ARGS+=	--enable-message-wins
CONFIGURE_ARGS+=	--enable-startup-notification

.include "../../devel/GConf2/schemas.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
