# $NetBSD: Makefile,v 1.3 2010/01/18 09:38:34 thomasklausner Exp $

DISTNAME=	TracScreenshots-0.1dev
PKGNAME=	trac-plugins-screenshots-0.1pre5002
PKGREVISION=	# blank on purpose even though pkglint moans
EGG_NAME=	${DISTNAME}
PKGREVISION=	1
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
