# $NetBSD: Makefile,v 1.1.1.1 2006/08/28 14:41:18 poppnk Exp $
#

DISTNAME=		afflib-1.6.31
CATEGORIES=		wip devel
MASTER_SITES=		http://www.afflib.org/downloads/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.afflib.org/downloads/
COMMENT=		Advanced Forensic Format library

USE_LANGUAGES= c++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aimage/aimage ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/aimage/ident ${PREFIX}/bin
	for tool in afcat afcompare afconvert affix afinfo afsegment afstats afxml ; do \
	${INSTALL_PROGRAM} ${WRKSRC}/tools/$$tool ${PREFIX}/bin ; done
	${INSTALL_DATA} ${WRKSRC}/lib/libafflib.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/afflib.h ${PREFIX}/include

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
