# $NetBSD: Makefile,v 1.1.1.1 2003/06/14 01:25:06 mjasm Exp $
#

DISTNAME=		libdisasm-0.17pre2
WRKSRC=         ${WRKDIR}/libdisasm_src-0.17
CATEGORIES=		wip
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bastard/}
EXTRACT_SUFX=	.tgz

MAINTAINER=		adam@monkeybyte.org
HOMEPAGE=		http://bastard.sourceforge.net/
COMMENT=		dissassembly library for ELF x86 binarys

do-build:
	cd ${WRKSRC}/src/arch/i386/libdisasm && make

do-install: do-install-dirs do-install-binaries do-install-docs

do-install-dirs:
	${INSTALL_DATA_DIR} ${PREFIX}/share/libdisasm

do-install-binaries:
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/quikdis ${PREFIX}/bin; \
	${INSTALL_SCRIPT} ${WRKSRC}/src/arch/i386/libdisasm/libdisasm.so ${PREFIX}/lib; \
	${INSTALL_SCRIPT} ${WRKSRC}/utils/op-conv.pl ${PREFIX}/bin;

do-install-docs:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/libdisasm

.include "../../mk/bsd.pkg.mk"
