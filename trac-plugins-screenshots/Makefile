# $NetBSD: Makefile,v 1.1.1.1 2009/01/21 13:07:49 rsmarples Exp $

DISTNAME=	TracScreenshots-0.1dev
PKGNAME=	trac-plugins-screenshots-0.1pre5002
EGG_NAME=	${DISTNAME}
CATEGORIES=	www

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/ScreenshotsPlugin
COMMENT=	Screenshots plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	screenshots
SVN_ROOT.screenshots=	http://trac-hacks.org/svn/screenshotsplugin/0.11
SVN_TAG.screenshots=	5002

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/screenshots

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
