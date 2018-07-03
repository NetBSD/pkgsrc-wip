# $NetBSD: Makefile,v 1.9 2015/08/04 20:04:16 thomasklausner Exp $

DISTNAME=	screenshotsplguin_0.11-r${SVN_REV}
PKGNAME=	trac-plugins-screenshots-0.1pre${SVN_REV}
PKGREVISION=	1
EGG_NAME=	TracScreenshots-0.7
CATEGORIES=	www
MASTER_SITES=	-https://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	https://trac-hacks.org/wiki/ScreenshotsPlugin
COMMENT=	Screenshots plugin for Trac

DEPENDS+=	trac>=0.11:../../www/trac

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-imaging

SVN_REV=	7703
SVN_MOD=	screenshotsplugin/0.11
WRKSRC=		${WRKDIR}/${SVN_MOD}

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type f -print | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../graphics/py-imaging/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
