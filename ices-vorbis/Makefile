# $NetBSD: Makefile,v 1.5 2012/09/30 05:17:18 asau Exp $
#

DISTNAME=		ices-${ICES_VERSION}
PKGNAME=		ices-vorbis-${ICES_VERSION}
ICES_VERSION=		2.0.1
CATEGORIES=		audio
MASTER_SITES=		http://svn.xiph.org/releases/ices/

MAINTAINER=		peter.schuller@infidyne.com
HOMEPAGE=		http://www.icecast.org/ices.php
COMMENT=		Vorbis source client for a streaming server

USE_TOOLS+=		automake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

pre-configure:
	cd ${WRKSRC} && autoreconf --force

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/ices ${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_MAN} ${WRKSRC}/debian/ices2.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${PKGBASE}.1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for i in basic.html config.html faq.html index.html inputs.html \
		intro.html style.css ; \
	do \
		${INSTALL_DATA} ${WRKSRC}/doc/$$i ${DESTDIR}${DOCDIR}/$$i ; \
	done
	for i in AUTHORS COPYING README  ; \
	do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DESTDIR}${DOCDIR}/$$i ; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	for i in ices-alsa.xml ices-oss.xml ices-playlist.xml ; \
	do \
		${INSTALL_DATA} ${WRKSRC}/conf/$$i ${DESTDIR}${EGDIR}/$$i ; \
	done

.include "../../mk/oss.buildlink3.mk"
.if defined(HAVE_OSS) && (${HAVE_OSS} == "YES")
CONFIGURE_ENV+=		ac_cv_libossaudio__oss_ioctl=no
.endif

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libshout/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
