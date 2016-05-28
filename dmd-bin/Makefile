# $NetBSD: Makefile,v 1.7 2012/09/28 21:24:37 asau Exp $
#

DISTNAME=		dmd
PKGNAME=		${DISTNAME}-bin-0.82
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.digitalmars.com/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.digitalmars.com/d/dcompiler.html
COMMENT=		The D Programming Language from Digital Mars


LINUX_BINPKG_FMT=	plain
HTMLDIR=		share/doc/${PKGNAME}

USE_TOOLS+=		pax

do-install:
	#
	# binaries
	#
	for a in dumpobj obj2asm dmd; do \
		${INSTALL_PROGRAM} ${WRKSRC}/bin/$$a ${EMULDIR}/usr/bin/$$a; \
	done
	#
	# libraries
	#
	${INSTALL_DATA} ${WRKSRC}/lib/libphobos.a ${EMULDIR}/usr/lib/libphobos.a
	#
	# docs
	#
	${INSTALL_DATA_DIR} ${PREFIX}/${HTMLDIR}
	cd ${WRKSRC}/html/d && pax -rw -pp [a-z]* ${PREFIX}/${HTMLDIR}
	#
	# sources
	#
	${INSTALL_DATA_DIR} ${EMULDIR}/usr/src
	cd ${WRKSRC}/src && pax -rw -pp * ${EMULDIR}/usr/src
	#
	# dmd.conf
	#
	${ECHO} "[Environment]" > ${WRKSRC}/dmd.conf
	${ECHO} "DFLAGS=-I/usr/src/phobos" >> ${WRKSRC}/dmd.conf
	${INSTALL_DATA} ${WRKSRC}/dmd.conf ${EMULDIR}/etc/dmd.conf

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
