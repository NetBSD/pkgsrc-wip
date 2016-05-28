# $NetBSD: Makefile,v 1.11 2013/06/21 14:32:18 noud4 Exp $

DISTNAME=	pdfedit-0.3.2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pdfedit/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	lkundrak@skosi.org
HOMEPAGE=	http://pdfedit.petricek.net/
COMMENT=	Editor for manipulating PDF documents
LICENSE=	gnu-gpl-v2


GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

.include "../../x11/qt3/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
