# $NetBSD: Makefile,v 1.1.1.1 2010/11/18 13:43:13 ryo-on Exp $
#

DISTNAME=	audiere-1.9.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=audiere/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://audiere.sourceforge.net/
COMMENT=	Audiere is a high-level audio API
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes

# XXX
BUILDLINK_TRANSFORM+=l:ogg:ogg:ossaudio

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
