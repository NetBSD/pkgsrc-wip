# $NetBSD: Makefile,v 1.1.1.2 2003/11/29 11:36:00 poppnk Exp $
#

DISTNAME=		gpdf-0.104
CATEGORIES=		wip print
MASTER_SITES=		http://ftp.gnome.org/pub/GNOME/sources/gpdf/0.104/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ftp.gnome.org/pub/GNOME/sources/gpdf/0.104/
COMMENT=		GNOME PDF Viewer

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../devel/libbonoboui/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
