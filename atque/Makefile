# $NetBSD: Makefile,v 1.1.1.1 2012/02/16 15:16:13 christtrekker Exp $
#

DISTNAME=	atque-1.1.1
CATEGORIES=	games editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=igniferroque/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://igniferroque.sourceforge.net/
COMMENT=	Marathon game map utility
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake gmake
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	boost-headers>=1.33:../../devel/boost-headers
DEPENDS+=	boost-libs>=1.33:../../devel/boost-libs

.include "../../mk/bsd.pkg.mk"
