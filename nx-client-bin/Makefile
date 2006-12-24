# $NetBSD: Makefile,v 1.1.1.1 2006/12/24 14:49:01 rumko Exp $

DISTNAME=	nxclient-${NX_VER}.i386
PKGNAME=	nx-client-bin-${NX_VER}
#PKGREVISION=
CATEGORIES=	net
MASTER_SITES=	http://web04.nomachine.com/download/2.1.0/Linux-NoXft/

MAINTAINER=	rumcic@gmail.com
COMMENT=	NX linux client binary

NX_VER=		2.1.0-11

WRKSRC?=	${WRKDIR}/NX
NO_CONFIGURE=	yes
USE_LANGUAGES=	# empty

INSTALLATION_DIRS=	bin

.include "../../emulators/suse_linux/Makefile.application"
DEPENDS+=	suse_libpng>=9.1:../../emulators/${SUSE_DIR_PREFIX}_libpng

do-build:

do-install:
	for file in nx*; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/$$file ${PREFIX}/bin; \
	done

.include "../../mk/bsd.pkg.mk"
