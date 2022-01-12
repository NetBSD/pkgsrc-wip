# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:39 wiz Exp $

DISTNAME=	subsync-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/subsync/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tympanix/subsync
COMMENT=	Synchronize your subtitles with machine learning
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-h5py-[0-9]*:../../devel/py-h5py
DEPENDS+=	${PYPKGPREFIX}-librosa-[0-9]*:../../wip/py-librosa
DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-pysrt-[0-9]*:../../textproc/py-pysrt

REPLACE_PYTHON+=	subsync/bin/subsync

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
