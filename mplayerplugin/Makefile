# $NetBSD: Makefile,v 1.4 2003/04/17 19:05:18 bmeurer Exp $
#

DISTNAME=	mplayerplug-in_v0.71
PKGNAME=	mplayerplugin-0.71
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mplayerplug-in/}

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://mplayerplug-in.sourceforge.net/
COMMENT=	Browser plugin that uses mplayer to play videos from websites

DEPENDS+=	mplayer-[0-9]*:../../graphics/mplayer
DEPENDS+=	mozilla-[0-9]*:../../www/mozilla

WRKSRC=         ${WRKDIR}/mplayerplug-in

USE_BUILDLINK2=	YES
USE_X11BASE=	YES

MOZ_PLUGDIR=    ${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA_DIR} ${MOZ_PLUGDIR}
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so ${MOZ_PLUGDIR}

.include "../../mk/bsd.pkg.mk"
