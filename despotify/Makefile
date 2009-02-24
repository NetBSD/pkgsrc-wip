# $NetBSD: Makefile,v 1.1.1.1 2009/02/24 15:28:09 pettai Exp $
#

DISTNAME=	despotify-r761
PKGNAME=	despotify-761
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=despotify/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://despotify.sourceforge.net/
COMMENT=	Open Source Spotify client

USE_TOOLS+=	gmake

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
