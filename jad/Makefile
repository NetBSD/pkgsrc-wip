# $NetBSD: Makefile,v 1.1.1.1 2004/11/03 16:26:26 poppnk Exp $
#

DISTNAME=		jadlx158
PKGNAME=		jad-1.5.8
CATEGORIES=		wip
MASTER_SITES=		http://www.kpdus.com/jad/linux/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.kpdus.com/jad.html
COMMENT=		The fast JAva Decompiler

WRKSRC=		${WRKDIR}
USE_BUILDLINK3=		yes

LICENSE=no-commercial-use
NO_BUILD=YES

# TODO add support for the rest of supported archs
ONLY_FOR_PLATFORM=Linux-*-i386

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jad ${PREFIX}/bin/jad
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jad/
	${INSTALL_DATA} ${WRKSRC}/Readme.txt ${PREFIX}/share/doc/jad/

.include "../../mk/bsd.pkg.mk"
