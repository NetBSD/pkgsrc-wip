# $NetBSD: Makefile,v 1.4 2005/04/11 21:15:21 tvierling Exp $
#

DISTNAME=		visionegg-contrib-0.9.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=visionegg/}
EXTRACT_SUFX=		.zip

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://visionegg.sourceforge.net/
COMMENT=		Additional modules for py-visionegg package

NO_BUILD=		# defined
PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

PY_VC_FILES_LABVIEW=	"Edit Grating C.vi" \
			"Grating C to A.vi" \
			"Grating C to python.vi" \
			"Grating Control.vi" \
			"Waveclip C to A.vi" \
			"Waveclip C to python.vi" \
			"Waveclip CA to A.vi" \
			"Waveclip CA to python.vi"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/VisionEgg-${PYVERSSUFFIX}/labview
	for a in ${PY_VC_FILES_LABVIEW}; do \
		${INSTALL_DATA} "${WRKSRC}/labview/$$a" \
			"${PREFIX}/share/VisionEgg-${PYVERSSUFFIX}/labview/$$a"; \
	done

.include "../../wip/py-visionegg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
