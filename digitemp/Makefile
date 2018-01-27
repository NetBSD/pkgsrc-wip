# $NetBSD: Makefile,v 1.1.1.1 2011/10/29 06:08:03 errellion Exp $
#

DISTNAME=	digitemp-3.6.0
CATEGORIES=	comms
MASTER_SITES=	http://www.digitemp.com/software/linux/

MAINTAINER=	bartosz@maciejewski.org
HOMEPAGE=	http://www.digitemp.com/
COMMENT=	Reads temperature from serial and USB thermometers
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin
PKG_DESTDIR_SUPPORT=	destdir
USE_TOOLS+=		gmake
BUILD_TARGET=		ds9097

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/digitemp_DS9097 ${DESTDIR}${PREFIX}/bin/digitemp

.include "../../mk/bsd.pkg.mk"
