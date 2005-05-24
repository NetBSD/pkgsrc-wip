# $NetBSD: Makefile,v 1.5 2005/05/24 10:30:58 rillig Exp $

DISTNAME=	lletters-0.1.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lln/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	lletters-media-0.1.9a.tar.gz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lln.sourceforge.net/
COMMENT=	Linux Letters and Numbers childrens game

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
CPPFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

pre-configure:
	${MV} ${WRKDIR}/sounds/* ${WRKSRC}/sounds/
	${MV} ${WRKDIR}/images/* ${WRKSRC}/images/

#.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
