# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:11 noud4 Exp $
#

DISTNAME=	contact-lookup-applet-0.17
CATEGORIES=	mail
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://www.burtonini.com/wordpress/?s=Contact+Lookup+Applet
COMMENT=	Gnome panel applet for easy Evolution contact book access
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		intltool
USE_TOOLS+=		perl
USE_TOOLS+=		pkg-config
USE_TOOLS+=		gettext
USE_TOOLS+=		gmake
USE_LANGUAGES+=		c

.include "../../x11/gnome-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.evolution-data-server+=	evolution-data-server>=2.24.3
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
