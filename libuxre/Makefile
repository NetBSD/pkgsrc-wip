# $NetBSD: Makefile,v 1.3 2006/12/18 16:06:22 cheusov Exp $

.include "../../wip/heirloom-dirs/Makefile.common"

PKGNAME=	libuxre-${HEIRLOOM_VER}
CATEGORIES=	devel

MAINTAINER=	cheusov@tut.by
COMMENT=	POSIX compatible regular expression library

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include/uxre share/doc/${PKGBASE}

pre-build:
	cd ${WRKSRC} && \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f makefile makefiles

DOC_FILES=	NOTES COPYING.LGPL
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

SRCFILES=	onefile    regfree    regerror    btowc
LOFILES=	onefile.lo regfree.lo regerror.lo btowc.lo

do-build:
	cd ${WRKSRC}/libuxre || exit 1; \
	for i in ${SRCFILES}; do \
	   libtool --mode=compile \
	      ${CC} -o $${i}.o -c ${CFLAGS} -I. $${i}.c || exit 2; \
	done; \
	libtool --mode=link ${CC} -o libuxre.la \
	   -rpath ${PREFIX}/lib -version-info 0:0 ${LOFILES}

do-install:
	libtool ${INSTALL_DATA} ${WRKSRC}/libuxre/libuxre.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuxre/regex.h ${PREFIX}/include/uxre
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/libuxre/"${i}" ${DOC_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
