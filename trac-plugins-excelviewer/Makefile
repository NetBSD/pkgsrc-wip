# $NetBSD: Makefile,v 1.3 2010/07/30 12:37:47 obache Exp $

DISTNAME=	excelviewerplugin-0.1dev_r${SVN_REV}
PKGNAME=	trac-plugins-excelviewer-0.1pre${SVN_REV}
EGG_NAME=	TracExcelViewer-0.1
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/ExcelViewerPlugin
COMMENT=	Excel viewer plugin for trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.10:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-xlrd>=0:../../wip/py-xlrd

SVN_REV=	687
SVN_MOD=	excelviewerplugin/0.10
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
