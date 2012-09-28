# $NetBSD: Makefile,v 1.6 2012/09/28 21:24:30 asau Exp $
#

DISTNAME=	dasm-${DISTVERSION}
DISTVERSION=	2.20.11
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dasm-dillon/}

MAINTAINER=	rhialto@falu.nl
HOMEPAGE=	http://dasm-dillon.sourceforge.net/
COMMENT=	Multi-CPU cross-assembler for 6502, 6803, 68HC11 and others
LICENSE=	gnu-gpl-v2

NO_CONFIGURE=	YES
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/dasm share/dasm/atari2600 share/dasm/channel-f

SHAREDIR=${DESTDIR}/${PREFIX}/share/dasm

do-install:
	${INSTALL_DATA_DIR} ${SHAREDIR}
	${INSTALL_DATA_DIR} ${SHAREDIR}/atari2600
	${INSTALL_DATA_DIR} ${SHAREDIR}/channel-f
.for f in dasm ftohex
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${DESTDIR}/${PREFIX}/bin
.endfor
.for f in AUTHORS FUTURE NEWS README README.ANDREW \
          doc/dasm.txt doc/ftohex.txt
	${INSTALL_DATA} ${WRKSRC}/${f} ${SHAREDIR}
.endfor
.for f in atari2600/macro.h atari2600/vcs.h \
          channel-f/README channel-f/macro.h channel-f/ves.h
	${INSTALL_DATA} ${WRKSRC}/machines/${f} ${SHAREDIR}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
.include "../../mk/tools/make.mk"
