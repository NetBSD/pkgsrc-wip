# $NetBSD: Makefile,v 1.2 2004/11/03 17:09:07 poppnk Exp $
#

DISTNAME=		jadlx158
PKGNAME=		jad-1.5.8
CATEGORIES=		wip
MASTER_SITES=		http://www.kpdus.com/jad/${JAD_OSDIR}
EXTRACT_SUFX=		.zip
JAD_OSDIR=		linux # Default one

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.kpdus.com/jad.html
COMMENT=		The fast JAva Decompiler

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=		yes

LICENSE=no-commercial-use
NO_BUILD=YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
DISTNAME=jadfb158
JAD_OSDIR=freebsd/
DISTINFO_FILE=${PKGDIR}/distinfo.FreeBSD
PLIST_SRC=${PKGDIR}/PLIST.FreeBSD
.endif

# TODO add support for the rest of supported archs
ONLY_FOR_PLATFORM=Linux-*-i386 FreeBSD-*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/jad
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jad/
	${INSTALL_DATA} ${WRKSRC}/?eadme.txt ${PREFIX}/share/doc/jad/

.include "../../mk/bsd.pkg.mk"
