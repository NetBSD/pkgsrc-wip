# $NetBSD: Makefile,v 1.4 2010/01/17 12:03:24 thomasklausner Exp $
#

DISTNAME=	despotify-r761
PKGNAME=	despotify-761
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=despotify/}

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://despotify.sourceforge.net/
COMMENT=	Open Source Spotify client

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
USE_NCURSES=	yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gateway ${DESTDIR}${PREFIX}/bin/gateway
	${INSTALL_PROGRAM} ${WRKSRC}/despotify ${DESTDIR}${PREFIX}/bin/despotify

.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
