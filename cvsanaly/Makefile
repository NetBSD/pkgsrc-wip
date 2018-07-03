# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:42 thomasklausner Exp $

DISTNAME=	cvsanaly2-2.0.0
CATEGORIES=	devel
MASTER_SITES=	http://forge.morfeo-project.org/frs/download.php/550/

MAINTAINER=	research.jihbed@gmail.com
HOMEPAGE=	http://tools.libresoft.es/cvsanaly
COMMENT=	Source code management tool analyzer
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mysqldb-[0-9]*:../../databases/py-mysqldb
DEPENDS+=	git>=1.7.0.5:../../devel/git

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-mysqldb

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,share/man/man1,man/man1,g'
SUBST_FILES.paths+=	setup.py
SUBST_MESSAGE.paths=	Fixing header search paths.

DOCDIR=	${PREFIX}/share/doc/cvsanaly

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}


.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/py-repositoryhandler/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
