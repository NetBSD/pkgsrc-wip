# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:43 thomasklausner Exp $

DISTNAME=	mne-0.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mne/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://martinos.org/mne/stable/index.html
COMMENT=	MNE python project for MEG and EEG data analysis
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
