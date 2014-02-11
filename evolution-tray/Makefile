# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:11 noud4 Exp $
#

DISTNAME=	evolution-tray-0.0.8
CATEGORIES=	mail
MASTER_SITES=	http://gnome.eu.org/

MAINTAINER=	noud4@users.sourceforge.net
HOMEPAGE=	http://gnome.eu.org/index.php/Evolution_Tray
COMMENT=	Put Evolution in tray
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config gmake
USE_LANGUAGES+=	c

.include "../../mail/evolution/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
