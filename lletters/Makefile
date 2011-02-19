# $NetBSD: Makefile,v 1.11 2011/02/19 09:16:18 mwdavies Exp $

DISTNAME=	lletters-0.1.9
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lln/}
DISTFILES=	${DEFAULT_DISTFILES} lletters-media-0.1.9a.tar.gz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://lln.sourceforge.net/
COMMENT=	Linux Letters and Numbers childrens game

USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
# Note: although pkglint warns about the following line, this exact form
# is required for autoconf2.12.
CPPFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

pre-configure:
	${MV} ${WRKDIR}/sounds/* ${WRKSRC}/sounds/
	${MV} ${WRKDIR}/images/* ${WRKSRC}/images/

#.include "../../x11/gtk/buildlink3.mk"
.include "../../graphics/imlib-gtk/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
