# $NetBSD: Makefile,v 1.7 2012/11/13 19:33:44 othyro Exp $
#

DISTNAME=	# SVN package
PKGNAME=	despotify-0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=despotify/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://despotify.sourceforge.net/
COMMENT=	Open Source Spotify client

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_NCURSES=	yes
WRKSRC=		${WRKDIR}/despotify/src

INSTALLATION_DIRS=	bin

post-extract:
	cp ${WRKSRC}/Makefile.local.mk.dist ${WRKSRC}/Makefile.local.mk

SVN_REPOSITORIES=	despotify
SVN_REPO.despotify=	http://svn.code.sf.net/p/despotify/code

PTHREAD_AUTO_VARS=	yes
.include "../../mk/pthread.buildlink3.mk"

.include "../../wip/mk/svn-package2.mk"
.include "../../audio/libao/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
