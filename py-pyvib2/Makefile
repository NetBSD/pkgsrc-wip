# $NetBSD: Makefile,v 1.2 2012/01/30 02:26:08 noud4 Exp $
#

DISTNAME=	pyvib2-1.1.tar
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/.tar//}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	http://pypi.python.org/packages/source/p/pyvib2/
EXTRACT_SUFX=	.gz#md5=960aaaeaee56d819c82fa8b878bf0158

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pyvib2.sourceforge.net/
COMMENT=	Analyzing vibrational motion and vibrational spectra
LICENSE=		gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-Pmw>=1.3.2:../../x11/py-Pmw

WRKSRC=		${WRKDIR}/pyvib2-1.1
USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-Tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
