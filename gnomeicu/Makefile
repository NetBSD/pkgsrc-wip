# $NetBSD: Makefile,v 1.3 2003/08/29 11:49:28 thomasklausner Exp $

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
USE_GMAKE=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GCONF2_SCHEMAS=		gnomeicu.schemas

.include "../../databases/gdbm/buildlink2.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../net/gnet1/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
