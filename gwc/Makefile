# $NetBSD: Makefile,v 1.1.1.1 2003/10/16 07:54:11 cubidou Exp $

DISTNAME=	gwc-0.19-10
PKGNAME=	gwc-0.19.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gwc/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	Benjamin.Wong@cc.gatech.edu
HOMEPAGE=	http://gwc.sourceforge.net/
COMMENT=	Gnome Wave Cleaner: dehiss and declick .wav files

GNU_CONFIGURE=	YES
USE_BUILDLINK2=	YES
USE_X11BASE=	YES

post-patch:
	${SED} -e s,@DEVOSSAUDIO@,${DEVOSSAUDIO}, ${WRKSRC}/gwc.c > ${WRKSRC}/gwc.c.sed
	${MV} ${WRKSRC}/gwc.c.sed ${WRKSRC}/gwc.c

.include "../../math/fftw/buildlink2.mk"
.include "../../audio/libsndfile/buildlink2.mk"
.include "../../x11/gnome-core/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
