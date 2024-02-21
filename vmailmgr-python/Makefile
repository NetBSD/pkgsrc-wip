# $NetBSD$

.include "../../wip/vmailmgr/Makefile.common"

PKGNAME=		vmailmgr-python-${VERSION}

CONFIGURE_ARGS+=	--enable-python
CONFIGURE_ENV+=		PYTHONBIN=${PYTHONBIN:Q}

BUILD_DIRS=		python
INSTALL_DIRS=		python

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

SUBST_CLASSES+=		pyversion
SUBST_STAGE.pyversion=	pre-configure
SUBST_FILES.pyversion=	configure.ac python/Makefile.am
SUBST_VARS.pyversion=	PYTHONBIN

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
