# $NetBSD: Makefile,v 1.2 2003/06/02 07:59:41 marc Exp $
#

DISTNAME=	xmule-1.4.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xmule/}

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.xmule.org/
COMMENT=	eDonkey2000 client based on eMule

BUILD_USES_MSGFMT=	YES
DEPENDS=		gnome2-dirs>=1.1:../../misc/gnome2-dirs
DEPENDS+=		wget>=1.8.2:../../net/wget

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES

CONFIGURE_ARGS+=	--without-included-gettext

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../textproc/expat/buildlink2.mk"
.include "../../x11/wxGTK/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
