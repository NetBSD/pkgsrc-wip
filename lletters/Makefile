# $NetBSD: Makefile,v 1.3 2004/05/04 02:26:31 blef Exp $

DISTNAME=	lletters-0.1.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lln/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	lletters-media-0.1.9a.tar.gz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lln.sourceforge.net/
COMMENT=	Linux Letters and Numbers childrens game

USE_BUILDLINK3=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
CPPFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

pre-configure:
	${MV} ${WRKDIR}/sounds/* ${WRKSRC}/sounds/
	${MV} ${WRKDIR}/images/* ${WRKSRC}/images/

#.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
