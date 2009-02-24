# $NetBSD: Makefile,v 1.2 2009/02/24 16:45:19 tnn2 Exp $
#

DISTNAME=	despotify-r761
PKGNAME=	despotify-761
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=despotify/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://despotify.sourceforge.net/
COMMENT=	Open Source Spotify client

USE_TOOLS+=	gmake
USE_NCURSES=	yes

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
