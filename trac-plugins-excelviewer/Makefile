# $NetBSD: Makefile,v 1.1.1.1 2008/01/23 08:40:43 obache Exp $

DISTNAME=	excelviewerplugin-0.1dev_r687
PKGNAME=	trac-plugins-excelviewer-0.1.687
EGG_NAME=	TracExcelViewer-0.1
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/ExcelViewerPlugin
COMMENT=	Excel viewer plugin for trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.10:../../www/trac
DEPENDS+=	${PYPKGPREFIX}-xlrd>=0:../../wip/py-xlrd

SVN_REPOSITORIES=	excel
SVN_ROOT.excel=		http://trac-hacks.org/svn/excelviewerplugin/0.10
SVN_MODULE.excel=	#
SVN_TAG.excel=		687

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/0.10

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

PRIVILEGED_STAGES+=	clean

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
