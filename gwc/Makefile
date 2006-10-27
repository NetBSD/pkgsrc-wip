# $NetBSD: Makefile,v 1.8 2006/10/27 04:50:53 shattered Exp $

DISTNAME=	gwc-0.19-10
PKGNAME=	gwc-0.19.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwc.sourceforge.net/
COMMENT=	Gnome Wave Cleaner: dehiss and declick .wav files

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LANGUAGES=	c

post-patch:
	${SED} -e s,@DEVOSSAUDIO@,${DEVOSSAUDIO}, ${WRKSRC}/gwc.c > ${WRKSRC}/gwc.c.sed
	${MV} ${WRKSRC}/gwc.c.sed ${WRKSRC}/gwc.c

.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
