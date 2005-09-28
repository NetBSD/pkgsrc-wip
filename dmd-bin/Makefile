# $NetBSD: Makefile,v 1.3 2005/09/28 14:24:39 rillig Exp $
#

DISTNAME=		dmd
PKGNAME=		${DISTNAME}-bin-0.82
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.digitalmars.com/
EXTRACT_SUFX=		.zip

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.digitalmars.com/d/dcompiler.html
COMMENT=		The D Programming Language from Digital Mars

LINUX_BINPKG_FMT=	plain
HTMLDIR=		share/doc/${PKGNAME}

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
	cd ${WRKSRC}/html/d && ${PAX} -rw -pe [a-z]* ${PREFIX}/${HTMLDIR}
	#
	# sources
	#
	${INSTALL_DATA_DIR} ${EMULDIR}/usr/src
	cd ${WRKSRC}/src && ${PAX} -rw -pe * ${EMULDIR}/usr/src
	#
	# dmd.conf
	#
	${ECHO} "[Environment]" > ${WRKSRC}/dmd.conf
	${ECHO} "DFLAGS=-I/usr/src/phobos" >> ${WRKSRC}/dmd.conf
	${INSTALL_DATA} ${WRKSRC}/dmd.conf ${EMULDIR}/etc/dmd.conf

.include "../../wip/mk/linuxbin.pkg.mk"
.include "../../mk/bsd.pkg.mk"
