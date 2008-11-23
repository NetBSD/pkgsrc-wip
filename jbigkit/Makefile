# $NetBSD: Makefile,v 1.2 2008/11/23 12:34:13 thomasklausner Exp $
#

DISTNAME=	jbigkit-1.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.cl.cam.ac.uk/~mgk25/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.cl.cam.ac.uk/~mgk25/jbigkit/
COMMENT=	Highly effective data compression algorithm for bi-level images

TEST_TARGET=	test

PKG_DESTDIR_SUPPORT=user-destdir

WRKSRC=	${WRKDIR}/jbigkit

INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 share/doc/jbig

do-install:
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libjbig/libjbig.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libjbig/jbig.doc \
		${DESTDIR}${PREFIX}/share/doc/jbig
	cd ${WRKSRC}/pbmtools \
		&& ${INSTALL_PROGRAM} jbgtopbm pbmtojbg  \
			${DESTDIR}${PREFIX}/bin          \
		&& ${INSTALL_MAN} jbgtopbm.1 pbmtojbg.1  \
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
