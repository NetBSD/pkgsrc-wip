# $NetBSD: Makefile,v 1.10 2004/04/12 03:18:09 blef Exp $

DISTNAME=	libtheora-1.0alpha3
CATEGORIES=	graphics
MASTER_SITES=	http://www.theora.org/files/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.theora.org/
COMMENT=	Video codec for Ogg multimedia streaming (nightly source)

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
PLIST_SUBST=	PKGNAME_NOREV=${PKGNAME_NOREV}

# XXX the Makefiles don't install examples yet
post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/encoder_example ${PREFIX}/bin/theora-encoder_example
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/player_example ${PREFIX}/bin/theora-player_example
	${INSTALL_PROGRAM} ${WRKSRC}/examples/.libs/dump_video ${PREFIX}/bin/theora-dump_video
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PKGNAME_NOREV}

# XXX SDL is for the player_example
.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
