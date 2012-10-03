# $NetBSD: Makefile,v 1.6 2012/10/03 08:17:45 asau Exp $
#

DISTNAME=	libdisasm-0.17pre2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bastard.sourceforge.net/
COMMENT=	Dissassembly library for ELF x86 binarys

WRKSRC=		${WRKDIR}/libdisasm_src-0.17

INSTALLATION_DIRS=	bin lib

do-build:
	cd ${WRKSRC}/src/arch/i386/libdisasm && make

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/libdisasm
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/quikdis \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/libdisasm.so \
		${DESTDIR}${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/utils/op-conv.pl ${DESTDIR}${PREFIX}/bin;
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/libdisasm

.include "../../mk/bsd.pkg.mk"
