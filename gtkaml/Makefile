# $NetBSD: Makefile,v 1.5 2012/09/29 00:50:41 asau Exp $
#

DISTNAME=	gtkaml-0.2.7.1
PKGREVISION=	1
CATEGORIES=	wip
MASTER_SITES=	http://gtkaml.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/gtkaml/
COMMENT=	Gtkaml is an xml parser that extends the Vala
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake


.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.vala+=	vala>=0.5.7nb1
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
