# $NetBSD: Makefile,v 1.8 2013/12/02 09:59:25 jihbed Exp $

DISTNAME=	MDAnalysis-0.7.7
PKGNAME=	${PYPKGPREFIX}-mdanalysis-0.7.7
CATEGORIES=	biology
MASTER_SITES=	http://mdanalysis.googlecode.com/files/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://code.google.com/p/mdanalysis/
COMMENT=   Library to analyze and manipulate molecular dynamics trajectories
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCLUDE_3X=yes	# biopython doesn't support it yet

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
DEPENDS+=	${PYPKGPREFIX}-biopython>=1.63:../../wip/biopython
.include "../../mk/bsd.pkg.mk"
