# $NetBSD: Makefile,v 1.1.1.1 2009/03/18 18:44:41 lexort Exp $

SVNVERSION=	4802
VERSION=	0.5.${SVNVERSION}
DISTNAME=	TracRoadmapHours-${VERSION}
PKGNAME=	trac-plugins-RoadmapHours-${VERSION}
# Empty to avoid default setting.
PKGREVISION=
EGG_NAME=	${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/RoadmapHoursPlugin
COMMENT=	RoadmapHours plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac
DEPENDS+=	trac-plugins-TimingAndEstimation>=0.7.6:../../wip/trac-plugins-TimingAndEstimation

SVN_REPOSITORIES=	plugin
SVN_ROOT.plugin=	http://trac-hacks.org/svn/roadmaphoursplugin/0.11
SVN_TAG.plugin=		${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

PRIVILEGED_STAGES+=	clean

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
