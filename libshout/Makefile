# $NetBSD: Makefile,v 1.3 2003/08/29 10:31:22 thomasklausner Exp $
#

DISTNAME=	libshout-1.0.9
CATEGORIES=	audio
MASTER_SITES=	http://developer.icecast.org/libshout/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://developer.icecast.org/libshout/
COMMENT=	Library for using icecast servers

GNU_CONFIGURE=		# defined
REAL_INSTALL=		${INSTALL} -c -o 0 -g 0

# The GNU Makefile in the distribution is stubborn about changing where
# docs and examples get installed, so...

.include "../../mk/bsd.prefs.mk"

do-install:
	${MKDIR} ${LOCALBASE}/share/examples/${PKGNAME}
	${MKDIR} ${LOCALBASE}/share/doc/${PKGNAME}
	${MKDIR} ${LOCALBASE}/include/shout
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/example/* ${LOCALBASE}/share/examples/${PKGNAME}"
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/doc/*.html ${LOCALBASE}/share/doc/${PKGNAME}"
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/shout.h ${LOCALBASE}/include/shout"
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/.libs/libshout.so* ${LOCALBASE}/lib"
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/.libs/libshout.la ${LOCALBASE}/lib"
	${SH} -c "${REAL_INSTALL} ${WRKSRC}/.libs/libshout.a ${LOCALBASE}/lib"

.include "../../mk/bsd.pkg.mk"
