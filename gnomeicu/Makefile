# $NetBSD: Makefile,v 1.5 2004/02/17 02:55:34 blef Exp $

DISTNAME=	gnomeicu-0.99
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

GCONF2_SCHEMAS=		gnomeicu.schemas

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../net/gnet1/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
