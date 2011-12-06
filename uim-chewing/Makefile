# $NetBSD: Makefile,v 1.4 2011/12/06 10:58:02 obache Exp $
#

DISTNAME=	uim-chewing-0.1.0
CATEGORIES=	inputmethod
MASTER_SITES=	http://uim.googlecode.com/files/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://code.google.com/p/uim/
COMMENT=	Chewing im for uim
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

.include "../../inputmethod/libchewing/buildlink3.mk"
.include "../../inputmethod/uim/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
