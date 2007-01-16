# $NetBSD: Makefile,v 1.5 2007/01/16 10:19:56 netcap Exp $
#

DISTNAME=		soundtouch-1.3.1
PKGNAME=                libSoundTouch-1.3.1
CATEGORIES=		audio
MASTER_SITES=		http://www.surina.net/soundtouch/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.surina.net/soundtouch/
COMMENT=		Audio Processing Library

WRKSRC=			${WRKDIR}/${DISTNAME}/
USE_TOOLS+=		gmake automake pkg-config
USE_LIBTOOL=            yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# For some reason this library contains a config/ directory with
# lots of broken symlinks.  Remove them here and add new one using
# patches/patch-ac.  Files were taken from Audacity, which is
# distributed with it's own version of SoundTouch. The patch was
# taken from FreeBSD Ports.
# Note: Probably we should split patch-ac or create it from scratch,
#       but it would be a lot better if it was fixed upstream. 
pre-patch:
	${RM} -rf ${WRKSRC}/config/*
	${FIND} ${WRKSRC} -name "Makefile.in*" -type f | ${XARGS} ${SED} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g'

post-patch: .SILENT
	${SED} -e 's|-O3|${CFLAGS:M*:Q}|; s|$$(prefix)/doc|$$(datadir)/doc|' \
		${WRKSRC}/source/example/bpm/Makefile.in \
		${WRKSRC}/source/example/SoundStretch/Makefile.in \
		${WRKSRC}/source/SoundTouch/Makefile.in \
		${WRKSRC}/include/Makefile.in ${WRKSRC}/Makefile.in
	# Fix for GCC 4.x
	${SED} -e 's|SoundTouch::||' ${WRKSRC}/include/SoundTouch.h
	${CHMOD} +rx ${WRKSRC}/config/install-sh

.include "../../mk/bsd.pkg.mk"
