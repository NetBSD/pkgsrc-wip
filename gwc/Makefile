# $NetBSD: Makefile,v 1.2 2004/04/27 00:35:37 blef Exp $

DISTNAME=	gwc-0.19-10
PKGNAME=	gwc-0.19.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://gwc.sourceforge.net/
COMMENT=	Gnome Wave Cleaner: dehiss and declick .wav files

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11BASE=	YES

post-patch:
	${SED} -e s,@DEVOSSAUDIO@,${DEVOSSAUDIO}, ${WRKSRC}/gwc.c > ${WRKSRC}/gwc.c.sed
	${MV} ${WRKSRC}/gwc.c.sed ${WRKSRC}/gwc.c

.include "../../math/fftw/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../x11/gnome-core/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
