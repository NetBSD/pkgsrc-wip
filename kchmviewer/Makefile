# $NetBSD: Makefile,v 1.1 2005/12/06 08:29:41 ianzag Exp $
#

DISTNAME=		kchmviewer-1.3
CATEGORIES=		x11 misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kchmviewer/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://kchmviewer.sourceforge.net/
COMMENT=		KchmViewer is a chm (MS HTML help file format) viewer

USE_TOOLS+=		gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
