# $NetBSD: Makefile,v 1.3 2004/05/07 01:58:09 xtraeme Exp $
#

DISTNAME=		matchbox-panel-0.8
CATEGORIES=		x11
MASTER_SITES=		http://matchbox.handhelds.org/sources/matchbox-panel/0.8/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://matchbox.handhelds.org/sources/matchbox-panel/0.8/
COMMENT=		Panel for Matchbox

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-small-icons
CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-nls

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../wip/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
