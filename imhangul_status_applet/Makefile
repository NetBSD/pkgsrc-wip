# $NetBSD: Makefile,v 1.6 2004/02/09 01:35:49 minskim Exp $
#

DISTNAME=		imhangul_status_applet-0.2
CATEGORIES=		korean inputmethod
MASTER_SITES=		http://download.kldp.net/imhangul/

MAINTAINER=		minskim@bawi.org
HOMEPAGE=		http://imhangul.kldp.net/\#APPLET
COMMENT=		GNOME2 applet to show imhangul status

DEPENDS=		imhangul>=0.9.6:../imhangul

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS=		imhangul_status.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../x11/gnome-panel/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
