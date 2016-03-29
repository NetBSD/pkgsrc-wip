# $NetBSD: Makefile,v 1.9 2015/08/04 20:04:15 thomasklausner Exp $

DISTNAME=	gitplugin_0.12-r${SVN_REV}
PKGNAME=	trac-plugins-GitPlugin-0.1pre${SVN_REV}
PKGREVISION=	1
EGG_NAME=	TracGit-0.12.0.2dev
CATEGORIES=	www
MASTER_SITES=	-https://trac-hacks.org/changeset/${SVN_REV}/${SVN_MOD}?old_path=/&format=zip
EXTRACT_SUFX=	.zip

MAINTAINER=	roy@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/wiki/GitPlugin
COMMENT=	GIT plugin for Trac
LICENSE=	gnu-gpl-v2

DEPENDS+=	trac>=0.12:../../www/trac
DEPENDS+=	git-base>=1.5.6:../../devel/git-base

SVN_REV=	7757
SVN_MOD=	gitplugin/0.12
WRKSRC=		${WRKDIR}/${SVN_MOD}

post-extract:
	find ${WRKSRC} -type f | xargs chmod +r

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
