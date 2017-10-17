# $NetBSD$

DISTNAME=	weboob-1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	https://symlink.me/attachments/download/289/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://weboob.org/
COMMENT=	Weboob, Web Out Of Browsers
LICENSE=	gnu-agpl-v3

DEPENDS+=	${PYPKGPREFIX}-requests>=2.7.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-feedparser>=5.1.3:../../textproc/py-feedparser
DEPENDS+=	${PYPKGPREFIX}-lxml>=3.4.4:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-prettytable>=0.7.2:../../textproc/py-prettytable
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.11:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-gdata>=2.0.18:../../www/py-gdata
DEPENDS+=	${PYPKGPREFIX}-cssselect>=0.9.1:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-html2text-[0-9]*:../../textproc/py-html2text
DEPENDS+=	${PYPKGPREFIX}-termcolor>=1.1.0:../../devel/py-termcolor
DEPENDS+=	${PYPKGPREFIX}-mechanize>=0.2.5:../../www/py-mechanize

USE_LANGUAGES=	# none


.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
