# $NetBSD: Makefile,v 1.1 2006/07/20 15:00:24 cheusov Exp $

.include "../../wip/heirloom/Makefile.common"

PKGNAME=	libuxre-${HEIRLOOM_VER}
CATEGORIES=	devel

MAINTAINER=	cheusov@tut.by
COMMENT=	POSIX compatible regular expression library

BUILD_DIRS=		libuxre
INSTALLATION_DIRS=	include/uxre share/doc/${PKGBASE}

pre-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f makefile makefiles

DOC_FILES=	NOTES COPYING.LGPL
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/libuxre/libuxre.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuxre/regex.h ${PREFIX}/include/uxre
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/libuxre/"${i}" ${DOC_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
