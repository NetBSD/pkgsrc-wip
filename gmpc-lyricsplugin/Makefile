# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:36 asau Exp $
#

DISTNAME=	gmpc-lyricsplugin-0.20.0
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/0.20.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/Lyrics
COMMENT=	Lyrics plugin for GMPC
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	intltool pkg-config

BUILDLINK_API_DEPENDS.gmpc+=	gmpc>=0.16.2
.include "../../audio/gmpc/buildlink3.mk"
BUILDLINK_API_DEPENDS.libmpd+=	libmpd>=0.15.98
.include "../../audio/libmpd/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.12.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
