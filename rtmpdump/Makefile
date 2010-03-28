# $NetBSD: Makefile,v 1.1.1.1 2010/03/28 21:28:11 ryo-on Exp $
#

DISTNAME=	rtmpdump-2.2b
CATEGORIES=	net multimedia
MASTER_SITES=	http://rtmpdump.mplayerhq.hu/download/

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://rtmpdump.mplayerhq.hu/download/
COMMENT=	Tools for handling RTMP stream

LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin \
			lib \
			lib/pkgconfig \
			${DOCSDIR} \
			${PKGMANDIR}/man1 \
			${PKGMANDIR}/man8

USE_TOOLS+=	pkg-config
BUILD_TARGET=	posix
BUILD_DIRS=	. \
		librtmp

PKGCONFIG_OVERRIDE+=	librtmp/librtmp.pc.in

PROGRAMFILES=	rtmpdump \
		rtmpgw \
		rtmpsrv \
		rtmpsuck

LIBFILES=	librtmp/librtmp.a

MANFILE1=	rtmpdump.1
MANFILE8=	rtmpgw.8

DOCFILES=	ChangeLog \
		README \
		rtmpdump.1.html \
		rtmpgw.8.html

post-install:
.for filename in ${PROGRAMFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/${filename} ${DESTDIR}${PREFIX}/bin
.endfor
.for filename in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor
	${INSTALL_MAN} ${WRKSRC}/${MANFILE1} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/${MANFILE8} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_LIB} ${WRKSRC}/${LIBFILES:Q} ${DESTDIR}${PREFIX}/lib

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
