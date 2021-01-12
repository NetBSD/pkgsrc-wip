# $NetBSD$

DISTNAME=	tex2pix-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	print python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tex2pix/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/tex2pix/
COMMENT=	Lightweight renderer of LaTeX to a variety of graphics formats
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

USE_LANGUAGES=	# none

DEPENDS+=	tex-latex-bin>=2010:../../print/tex-latex-bin

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
