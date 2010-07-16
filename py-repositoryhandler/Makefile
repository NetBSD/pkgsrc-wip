# $NetBSD: Makefile,v 1.1.1.1 2010/07/16 19:17:10 jihbed Exp $
#

DISTNAME=	repositoryhandler-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://forge.morfeo-project.org/frs/download.php/530/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://forge.morfeo-project.org/projects/libresoft-tools/
COMMENT=	RepositoryHandler is a python library for handling code repositories
LICENSE=	gnu-gpl-v2

DEPENDS+=	bzr>=2.0.3:../../devel/bzr
DEPENDS+=	scmgit>=1.7.0.5:../../devel/scmgit

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config gmake
USE_LANGUAGES=	# none

PKGCONFIG_OVERRIDE+=	repositoryhandler.pc.in

PYTHON_VERSIONS_ACCEPTED= 26 25 24
PY_PATCHPLIST=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}

DOCDIR=	${PREFIX}/share/doc/repositoryhandler
INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
