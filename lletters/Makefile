# $NetBSD: Makefile,v 1.2 2004/01/25 02:32:23 grantbeattie Exp $

DISTNAME=	lletters-0.1.9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lln/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	lletters-media-0.1.9a.tar.gz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lln.sourceforge.net/
COMMENT=	Linux Letters and Numbers childrens game

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
CPPFLAGS+=		-DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\"

pre-configure:
	${MV} ${WRKDIR}/sounds/* ${WRKSRC}/sounds/
	${MV} ${WRKDIR}/images/* ${WRKSRC}/images/

#.include "../../x11/gtk/buildlink2.mk"
.include "../../graphics/imlib/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
