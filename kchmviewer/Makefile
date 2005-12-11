# $NetBSD: Makefile,v 1.2 2005/12/11 09:41:42 thomasklausner Exp $
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

BUILDLINK_DEPMETHOD.qt3-tools+=	build

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
