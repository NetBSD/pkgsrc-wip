# $NetBSD: Makefile,v 1.5 2014/01/18 19:56:17 thomasklausner Exp $

DISTNAME=	pyvib2-1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyvib2/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyvib2.sourceforge.net/
COMMENT=	Analyzing vibrational motion and vibrational spectra
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-Tk-[0-9]*:../../x11/py-Tk

PYTHON_VERSIONED_DEPENDENCIES=	Pmw

WRKSRC=		${WRKDIR}/pyvib2-1.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG=	yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
