# $NetBSD: Makefile,v 1.2 2003/04/15 21:29:53 xtraeme Exp $
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
USE_X11=	YES

MOZ_PLUGDIR=    ${PREFIX}/lib/mozilla/plugins

do-install:
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so ${MOZ_PLUGDIR}

.include "../../mk/bsd.pkg.mk"
