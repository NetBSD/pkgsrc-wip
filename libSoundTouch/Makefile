# $NetBSD: Makefile,v 1.9 2012/10/03 09:10:36 asau Exp $
#

DISTNAME=		soundtouch-1.7.0
PKGNAME=		libSoundTouch-1.7.0
CATEGORIES=		audio
MASTER_SITES=		http://www.surina.net/soundtouch/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.surina.net/soundtouch/
COMMENT=		Audio Processing Library
LICENSE=		gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/soundtouch/
USE_TOOLS+=		aclocal autoconf autoheader automake gmake gsed pkg-config
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

# For some reason this library contains a config/ directory with
# lots of broken symlinks.  Remove them here and add new one using
# patches/patch-ac.  Files were taken from Audacity, which is
# distributed with it's own version of SoundTouch. The patch was
# taken from FreeBSD Ports.
# Note: Probably we should split patch-ac or create it from scratch,
#       but it would be a lot better if it were fixed upstream.
pre-patch:
	${RM} -rf ${WRKSRC}/config/*

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

post-configure:
	gsed -i -e 's|-O3|${CFLAGS:M*:Q}|; s|$$(prefix)/doc|$$(datadir)/doc|' \
		${WRKSRC}/source/SoundTouch/Makefile \
		${WRKSRC}/include/Makefile.in ${WRKSRC}/Makefile
	# Fix for GCC 4.x
	gsed -i -e 's|SoundTouch::||' ${WRKSRC}/include/SoundTouch.h
	${CHMOD} +rx ${WRKSRC}/config/install-sh

.include "../../mk/bsd.pkg.mk"
