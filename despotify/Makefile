# $NetBSD: Makefile,v 1.5 2010/02/02 18:17:18 tnn2 Exp $
#

DISTNAME=	# SVN package
PKGNAME=	despotify-0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=despotify/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://despotify.sourceforge.net/
COMMENT=	Open Source Spotify client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_NCURSES=	yes
WRKSRC=		${WRKDIR}/despotify/src

INSTALLATION_DIRS=	bin

post-extract:
	cp ${WRKSRC}/Makefile.local.mk.dist ${WRKSRC}/Makefile.local.mk

SVN_REPOSITORIES=	despotify
SVN_ROOT.despotify=	http://despotify.svn.sourceforge.net/svnroot/despotify
SVN_MODULE.despotify=	despotify

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

.include "../../wip/mk/svn-package.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
