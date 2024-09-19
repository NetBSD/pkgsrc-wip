# $NetBSD: Makefile,v 1.7 2013/01/29 13:51:21 jihbed Exp $
#

DISTNAME=	gtkaml-0.4.3
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://gtkaml.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://code.google.com/p/gtkaml/
COMMENT=	Gtkaml is an xml parser that extends the Vala
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake

.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
