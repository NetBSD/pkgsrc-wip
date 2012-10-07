# $NetBSD: Makefile,v 1.8 2012/10/07 13:47:42 asau Exp $
#

DISTNAME=		visionegg-0.9.9-demo
PKGNAME=		py-visionegg-docs-0.9.9
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Documentation for py-visionegg in HTML format

NO_BUILD=		yes
USE_TOOLS+=		pax

PY_VE_DOC_DIR=		${PREFIX}/share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PY_VE_DOC_DIR}
	cd ${WRKSRC}/doc/visionegg && pax -rw -pe * ${DESTDIR}${PY_VE_DOC_DIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${PY_VE_DOC_DIR}/reference
	cd ${WRKSRC}/doc/reference/html && pax -rw -pe * \
		${DESTDIR}${PY_VE_DOC_DIR}/reference

.include "../../mk/bsd.pkg.mk"
