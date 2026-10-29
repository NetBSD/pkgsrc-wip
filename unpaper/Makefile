# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:52 othyro Exp $

DISTNAME=	unpaper-7.0.0
CATEGORIES=	textproc
MASTER_SITES=	https://www.flameeyes.eu/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.flameeyes.eu/projects/unpaper
COMMENT=	Post-processing scanned and photocopied book pages
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-sphinx-[0-9]*:../../textproc/py-sphinx

USE_TOOLS+=	pkg-config

pre-configure:
	${LN} -s ${PREFIX}/bin/sphinx-build-${PYVERSSUFFIX} ${TOOLS_DIR}/bin/sphinx-build

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/ffmpeg8/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
