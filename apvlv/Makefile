# $NetBSD: Makefile,v 1.8 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	apvlv-0.0.9.2
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://apvlv.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apvlv.googlecode.com/
COMMENT=	PDF Viewer which behaves like Vim
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../print/poppler-glib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
