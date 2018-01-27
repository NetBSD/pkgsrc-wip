# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:21 othyro Exp $
#

DISTNAME=		jadlx158
PKGNAME=		jad-1.5.8
CATEGORIES=		lang
MASTER_SITES=		http://www.kpdus.com/jad/${JAD_OSDIR}
EXTRACT_SUFX=		.zip
JAD_OSDIR=		linux # Default one

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.kpdus.com/jad.html
COMMENT=		The fast Java Decompiler
LICENSE=		no-commercial-use

WRKSRC=		${WRKDIR}

NO_BUILD=	YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
DISTNAME=	jadfb158
JAD_OSDIR=	freebsd/
DISTINFO_FILE=	${PKGDIR}/distinfo.FreeBSD
PLIST_SRC=	${PKGDIR}/PLIST.FreeBSD
.endif

.if ${OPSYS} == "OpenBSD"
DISTNAME=	jadob158
JAD_OSDIR=	openbsd/
DISTINFO_FILE=	${PKGDIR}/distinfo.OpenBSD
PLIST_SRC=	${PKGDIR}/PLIST.FreeBSD
.endif

# TODO add support for the rest of supported archs
ONLY_FOR_PLATFORM=	Linux-*-i386 FreeBSD-*-i386 OpenBSD-2.*-i386

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${DESTDIR}${PREFIX}/bin/jad
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/jad/
	${INSTALL_DATA} ${WRKSRC}/?eadme.txt ${DESTDIR}${PREFIX}/share/doc/jad/

.include "../../mk/bsd.pkg.mk"
