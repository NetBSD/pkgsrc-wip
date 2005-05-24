# $NetBSD: Makefile,v 1.9 2005/05/24 10:31:00 rillig Exp $
#

DISTNAME=	matchbox-panel-0.9.1
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/matchbox/sources/matchbox-panel/0.9/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://projects.o-hand.com/matchbox/
COMMENT=	Panel for Matchbox

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-small-icons
CONFIGURE_ARGS+=	--enable-startup-notification
CONFIGURE_ARGS+=	--enable-nls

BUILD_DEPENDS+=		gettext>=0.11.5:../../devel/gettext

CONFIGURE_ENV+=		XGETTEXT=${LOCALBASE}/bin/xgettext
CONFIGURE_ENV+=		GMSGFMT=${LOCALBASE}/bin/msgfmt
CONFIGURE_ENV+=		MSGFMT=${LOCALBASE}/bin/msgfmt
CONFIGURE_ENV+=		MSGMERGE=${LOCALBASE}/bin/msgmerge

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/libmatchbox/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
