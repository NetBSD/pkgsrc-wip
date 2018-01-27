# $NetBSD: Makefile,v 1.12 2015/08/04 20:04:16 thomasklausner Exp $

SVNVERSION=	11739
# Eggs do not have the same name and do not include the SVN revision.
EGG_VERSION=	1.2.8
VERSION=	${EGG_VERSION}.${SVNVERSION}
DISTNAME=	TracTimingAndEstimation-${VERSION}
EGG_NAME=	timingandestimationplugin-${EGG_VERSION}
PKGNAME=	trac-plugins-TimingAndEstimation-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://trac-hacks.org/wiki/TimingAndEstimationPlugin
COMMENT=	TimingAndEstimation plugin for Trac

DEPENDS+=	trac>=0.12:../../www/trac

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 1.2.8/11739

SVN_REPOSITORIES=	plugin
SVN_REPO.plugin=	https://trac-hacks.org/svn/timingandestimationplugin/branches/trac0.12
SVN_REVISION.plugin=	${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

# Bogus, but needed because setup runs as root during build.
PRIVILEGED_STAGES+=	clean

REPLACE_PYTHON=	scripts/trac-post-commit.py

EGDIR=		share/examples/trac
INSTALLATION_DIRS+=	${EGDIR}

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/trac-post-commit.py ${DESTDIR}${PREFIX}/${EGDIR}/TimingAndEstimation-post-commit.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
