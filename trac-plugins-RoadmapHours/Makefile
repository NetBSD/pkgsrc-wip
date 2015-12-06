# $NetBSD: Makefile,v 1.5 2015/08/04 20:04:16 thomasklausner Exp $

SVNVERSION=	4802
# Eggs do not have the same name and do not include the SVN revision.
EGG_VERSION=	0.5
VERSION=	${EGG_VERSION}.${SVNVERSION}
DISTNAME=	TracRoadmapHours-${VERSION}
EGG_NAME=	RoadmapHours-${EGG_VERSION}
PKGNAME=	trac-plugins-RoadmapHours-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/RoadmapHoursPlugin
COMMENT=	RoadmapHours plugin for Trac

DEPENDS+=	trac>=0.11:../../www/trac
DEPENDS+=	trac-plugins-TimingAndEstimation>=0.7.6:../../wip/trac-plugins-TimingAndEstimation

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # trac-plugins-TimingAndEstimation

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
