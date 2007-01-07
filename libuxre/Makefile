# $NetBSD: Makefile,v 1.5 2007/01/07 13:40:37 cheusov Exp $

.include "../../wip/heirloom-common/Makefile.common"

PKGNAME=	libuxre-${HEIRLOOM_VER}
CATEGORIES=	devel

MAINTAINER=	cheusov@tut.by
COMMENT=	POSIX compatible regular expression library

USE_LIBTOOL=		yes

INSTALLATION_DIRS=	include/uxre share/doc/${PKGBASE}

pre-build:
	cd ${WRKSRC} && \
	env ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f makefile makefiles

DOC_FILES=	NOTES COPYING.LGPL
DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}

SRCFILES=	onefile    regfree    regerror    btowc
LOFILES=	onefile.lo regfree.lo regerror.lo btowc.lo

do-build:
	set -e; \
	cd ${WRKSRC}/libuxre; \
	for i in ${SRCFILES}; do \
	   ${LIBTOOL} --mode=compile \
	      ${CC} -o "$${i}".o -c ${CFLAGS} -I. "$${i}".c; \
	done; \
	${LIBTOOL} --mode=link ${CC} -o libuxre.la \
	   -rpath ${PREFIX}/lib -version-info 0:0 ${LOFILES}

do-install:
	${LIBTOOL} ${INSTALL_DATA} ${WRKSRC}/libuxre/libuxre.la ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libuxre/regex.h ${PREFIX}/include/uxre
.for i in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/libuxre/"${i}" ${DOC_DIR}
.endfor

.include "../../mk/bsd.pkg.mk"
