# $NetBSD: Makefile,v 1.1.1.1 2004/03/19 18:04:49 xtraeme Exp $
#

DISTNAME=		matchbox-panel-0.8
CATEGORIES=		x11
MASTER_SITES=		http://matchbox.handhelds.org/sources/matchbox-panel/0.8/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://matchbox.handhelds.org/sources/matchbox-panel/0.8/
COMMENT=		Panel for Matchbox

DEPENDS+=		gnome2-dirs>=1.5:../../misc/gnome2-dirs
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
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
