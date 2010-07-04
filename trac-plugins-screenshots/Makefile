# $NetBSD: Makefile,v 1.4 2010/07/04 19:10:03 rsmarples Exp $

DISTNAME=	screenshotsplguin_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-screenshots-0.1pre${SVN_REV}
EGG_NAME=	TracScreenshots-0.1dev
CATEGORIES=	www
MASTER_SITES=	-http://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/ScreenshotsPlugin
COMMENT=	Screenshots plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REV=	7703
SVN_MOD=	screenshotsplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
