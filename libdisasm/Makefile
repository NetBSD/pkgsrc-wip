# $NetBSD: Makefile,v 1.3 2004/04/15 11:04:53 jmmv Exp $
#

DISTNAME=	libdisasm-0.17pre2
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	adam@monkeybyte.org
HOMEPAGE=	http://bastard.sourceforge.net/
COMMENT=	Dissassembly library for ELF x86 binarys

WRKSRC=		${WRKDIR}/libdisasm_src-0.17

do-build:
	cd ${WRKSRC}/src/arch/i386/libdisasm && make

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/libdisasm
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/quikdis \
		${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/libdisasm.so \
		${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/utils/op-conv.pl ${PREFIX}/bin;
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/libdisasm

.include "../../mk/bsd.pkg.mk"
