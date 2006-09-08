# $NetBSD: Makefile,v 1.1.1.1 2006/09/08 04:18:14 samott Exp $

DISTNAME=	quickie-1.1
CATEGORIES=	www
MASTER_SITES=	http://${PKGBASE}.sourceforge.net/ \
		http://mirror.inerd.com/FreeBSD/distfiles/${PKGBASE}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}.pdf
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

HOMEPAGE=	http://${PKGBASE}.sourceforge.net/

MAINTAINER=	shaun@inerd.com
COMMENT=	Small footprint, fast Wiki engine written in C++

USE_LANGUAGES=	c c++

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX}		\
		--sysconfdir=${PREFIX}/etc	\
		--localstatedir=${DATADIR}

DATADIR=	${PREFIX}/share/${PKGBASE}
DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

post-patch:
.if ${OPSYS:tl} != "linux"
	${CP} ${FILESDIR}/netbsd.h ${WRKSRC}/lib
.endif

pre-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	${INSTALL_DATA_DIR} ${DATADIR}/admin
	${INSTALL_DATA_DIR} ${DATADIR}/manual

	${INSTALL_DATA_DIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.pdf ${DOCSDIR}

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
