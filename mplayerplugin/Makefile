# $NetBSD: Makefile,v 1.1.1.1 2003/04/14 03:58:25 xtraeme Exp $
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/mplayerplug-in.so \
	${X11BASE}/lib/mozilla/plugins/

.include "../../mk/bsd.pkg.mk"
