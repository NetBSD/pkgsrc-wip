# $NetBSD$

DISTNAME=	HTSeq-${PORTVERSION}
PKGNAME=	${PYPKGPREFIX}-htseq-${PORTVERSION}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=H/HTSeq/}

MAINTAINER=	bacon@NetBSD.org
COMMENT=	Framework to analyze data from high-throughput sequencing assays
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-matplotlib-[0-9]*:../../graphics/py-matplotlib

# Just assuming C and C++: Adjust this!
USE_LANGUAGES=	c c++

PORTVERSION=	0.6.1p1

.include "../../lang/python/distutils.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
