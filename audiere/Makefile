# $NetBSD: Makefile,v 1.4 2012/09/24 16:56:40 asau Exp $
#

DISTNAME=	audiere-1.9.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiere/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://audiere.sourceforge.net/
COMMENT=	Audiere is a high-level audio API
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

# XXX
BUILDLINK_TRANSFORM+=	l:ogg:ogg:ossaudio

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
