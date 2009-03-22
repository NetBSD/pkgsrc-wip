# $NetBSD: Makefile,v 1.1.1.1 2009/03/22 00:05:02 jihbed Exp $
#

DISTNAME=	gtkaml-0.2.4
CATEGORIES=	textproc
MASTER_SITES=	http://gtkaml.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://code.google.com/p/gtkaml/
COMMENT=	Gtkaml is an XML parser that extends the Vala

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
