# $NetBSD: Makefile,v 1.1 2005/03/30 09:15:25 ianzag Exp $
#

DISTNAME=		kchm-0.6.5
CATEGORIES=		kde misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kchmnew/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kchmnew.sourceforge.net/
COMMENT=		KDE CHM file viewer

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=		YES
USE_LIBTOOL=	YES
USE_GNU_TOOLS+=	make

# Note: put app specific data files into kde dir
CONFIGURE_ARGS+= --datadir=${PREFIX}/share/kde

.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
