# $NetBSD: Makefile,v 1.8 2010/12/16 16:07:55 lexort Exp $

SVNVERSION=	5370
# Eggs do not have the same name and do not include the SVN revision.
EGG_VERSION=	0.7.6
VERSION=	${EGG_VERSION}.${SVNVERSION}
DISTNAME=	TracTimingAndEstimation-${VERSION}
EGG_NAME=	timingandestimationplugin-${EGG_VERSION}
PKGNAME=	trac-plugins-TimingAndEstimation-${VERSION}
# Empty to avoid default setting.
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac-hacks.org/wiki/TimingAndEstimationPlugin
COMMENT=	TimingAndEstimation plugin for Trac

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	{ja-,}trac>=0.11:../../www/trac

SVN_REPOSITORIES=	plugin
SVN_ROOT.plugin=	http://trac-hacks.org/svn/timingandestimationplugin/branches/trac0.11
SVN_TAG.plugin=		${SVNVERSION}

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
