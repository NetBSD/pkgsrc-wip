# $NetBSD: Makefile,v 1.3 2005/04/11 21:15:22 tvierling Exp $
#

DISTNAME=		visionegg-0.9.9-demo
PKGNAME=		py-visionegg-docs-0.9.9
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Documentation for py-visionegg in HTML format

NO_BUILD=		# defined

PY_VE_DOC_DIR=		${PREFIX}/share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PY_VE_DOC_DIR}
	cd ${WRKSRC}/doc/visionegg && ${PAX} -rw -pe * ${PY_VE_DOC_DIR}
	${INSTALL_DATA_DIR} ${PY_VE_DOC_DIR}/reference
	cd ${WRKSRC}/doc/reference/html && ${PAX} -rw -pe * \
		${PY_VE_DOC_DIR}/reference

.include "../../mk/bsd.pkg.mk"
