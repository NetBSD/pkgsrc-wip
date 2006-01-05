# $NetBSD: Makefile,v 1.3 2006/01/05 10:11:26 ghen Exp $
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
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
