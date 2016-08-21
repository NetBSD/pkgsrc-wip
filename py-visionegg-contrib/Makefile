# $NetBSD: Makefile,v 1.14 2014/05/09 07:38:51 thomasklausner Exp $

DISTNAME=		visionegg-contrib-0.9.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=		3
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Additional modules for py-visionegg package

NO_BUILD=		yes
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PY_VC_FILES_LABVIEW=	"Edit Grating C.vi" \
			"Grating C to A.vi" \
			"Grating C to python.vi" \
			"Grating Control.vi" \
			"Waveclip C to A.vi" \
			"Waveclip C to python.vi" \
			"Waveclip CA to A.vi" \
			"Waveclip CA to python.vi"

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/VisionEgg-${PYVERSSUFFIX}/labview
	for a in ${PY_VC_FILES_LABVIEW}; do \
		${INSTALL_DATA} "${WRKSRC}/labview/$$a" \
			"${DESTDIR}${PREFIX}/share/VisionEgg-${PYVERSSUFFIX}/labview/$$a"; \
	done

.include "../../wip/py-visionegg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
