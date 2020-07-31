# $NetBSD: $

SVNVERSION=	17747
# Eggs do not have the same name and do not include the SVN revision.
EGG_VERSION=	0.4.0
VERSION=	${EGG_VERSION}.${SVNVERSION}
DISTNAME=	TracPastePlugin-${VERSION}
EGG_NAME=	pasteplugin-${EGG_VERSION}
PKGNAME=	trac-plugins-Paste-${VERSION}
# Empty to avoid default setting.
#PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	# not defined

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	https://trac-hacks.org/wiki/TracPastePlugin
COMMENT=	Paste plugin for Trac
LICENSE=	original-bsd

DEPENDS+=	trac>=1.4:../../www/trac
DEPENDS+=	py27-pygments>=2.5:../../textproc/py-pygments

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.2.8/11739

SVN_REPOSITORIES=	plugin
SVN_REPO.plugin=	https://trac-hacks.org/svn/tracpasteplugin/trunk
SVN_REVISION.plugin=	${SVNVERSION}

NO_CHECKSUM=	yes

WRKSRC=		${WRKDIR}/plugin

# Bogus, but needed because setup runs as root during build.
PRIVILEGED_STAGES+=	clean

EGDIR=		share/examples/trac
INSTALLATION_DIRS+=	${EGDIR}

post-extract:
	find ${WRKSRC} -type d -name .svn -print | xargs rm -r

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
