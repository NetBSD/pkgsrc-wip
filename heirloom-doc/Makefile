# $NetBSD: Makefile,v 1.1 2006/12/17 15:05:13 cheusov Exp $

.include "../../wip/heirloom-dirs/Makefile.prog.common"

PKGNAME=	heirloom-doc-${HEIRLOOM_VER}
CATEGORIES=	sysutils

MAINTAINER=	cheusov@tut.by
COMMENT=	Collection of standard Unix utilities

DEPENDS+=	heirloom-dirs-${HEIRLOOM_VER}:../../wip/heirloom-dirs

DOC_FILES=	COPYING COPYING.LGPL \
		LICENSE LUCENT \
		OPENSOLARIS.LICENSE README

DOC_DIR=	${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=${DOC_DIR} ${DOC_DIR}/LICENSE

MAKE_FLAGS+=	SUBDIRS=build

do-build:
	cd ${WRKSRC}/build && make && cd .. && make -f Makefile intro.1

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DOC_DIR} || exit 1; \
	for i in ${DOC_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/LICENSE/$${i} \
		                ${DOC_DIR}/LICENSE || exit 1; \
	done; \
	${INSTALL_MAN} ${WRKSRC}/intro.1 ${PREFIX}/${HLROOT}/man/man1

.include "../../mk/bsd.pkg.mk"
