# $NetBSD: Makefile,v 1.6 2010/06/13 22:46:56 thomasklausner Exp $
#

DISTNAME=	apvlv-0.0.9.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://apvlv.googlecode.com/files/

MAINTAINER=	leot1990@users.sourceforge.net
HOMEPAGE=	http://apvlv.googlecode.com/
COMMENT=	PDF Viewer which behaves like Vim
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
