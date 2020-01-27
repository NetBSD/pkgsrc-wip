# $NetBSD$

PKGNAME=	uzbl-0.9.1
DISTNAME=	${PKGBASE}-v${PKGVERSION}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=uzbl/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uzbl.org/
COMMENT=	Web interface tools which adhere to the UNIX philosophy
LICENSE=	gnu-gpl-v3

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=	gmake pkg-config
# Support removed in v0.9.0, to come back in v1.0.
#MAKE_ENV+=	ENABLE_WEBKIT2=yes

PYTHON_VERSIONS_INCOMPATIBLE=	27
PY_PATCHPLIST=		yes
.include "../../lang/python/extension.mk"
MAKE_ENV+=	PYTHON=${PYTHONBIN}
MAKE_ENV+=	MANDIR=${DESTDIR}/${PREFIX}/${PKGMANDIR}

# don't include lang/python/egg.mk. define onwn EGG_NAME, INFODIR.
# when include egg.mk, defined PYDISTUTILSPKG=yes
# then run do-build and do-install in lang/python/extension.mk
EGG_NAME=	uzbl-201100808
PLIST_SUBST+=	EGG_INFODIR=${EGG_NAME}-py${PYVERSSUFFIX}.egg-info

REPLACE_PYTHON+=	bin/uzbl-tabbed
REPLACE_PYTHON+=	examples/data/scripts/auth.py
REPLACE_PYTHON+=	examples/data/scripts/uzblcat
REPLACE_PYTHON+=	examples/data/scripts/per-site-settings.py
REPLACE_PYTHON+=	examples/data/scripts/scheme.py
.include "../../lang/python/application.mk"

post-install:
	${RM} ${DESTDIR}/${PREFIX}/share/uzbl/examples/config/config.orig

# for uzbl-browser
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
# for uzbl-tabbed with GTK+ 2
#DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2

# TODO: make an option for GTK version
#.include "../../www/webkit24-gtk/buildlink3.mk"
# or
.include "../../www/webkit24-gtk3/buildlink3.mk"

.include "../../security/gnutls/buildlink3.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
