# $NetBSD: Makefile,v 1.6 2006/05/19 16:51:34 ykomatsu Exp $
#

DISTNAME=		visionegg-0.9.9-demo
PKGNAME=		py-visionegg-docs-0.9.9
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Documentation for py-visionegg in HTML format

NO_BUILD=		yes

PY_VE_DOC_DIR=		${PREFIX}/share/doc/${PKGNAME}

do-install:
	${INSTALL_DATA_DIR} ${PY_VE_DOC_DIR}
	cd ${WRKSRC}/doc/visionegg && ${PAX} -rw -pe * ${PY_VE_DOC_DIR}
	${INSTALL_DATA_DIR} ${PY_VE_DOC_DIR}/reference
	cd ${WRKSRC}/doc/reference/html && ${PAX} -rw -pe * \
		${PY_VE_DOC_DIR}/reference

.include "../../mk/bsd.pkg.mk"
