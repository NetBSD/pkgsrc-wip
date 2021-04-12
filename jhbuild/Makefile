# $NetBSD$

DISTNAME=	jhbuild-3.38.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.gnome.org/GNOME/jhbuild/-/archive/3.38.0/

MAINTAINER=	cirnatdan@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/jhbuild/-/archive/3.38.0/
COMMENT=	Build collections of source packages
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		pkg-config autoconf automake gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c

PKGCONFIG_OVERRIDE+=	tests/libhello/libhello.pc.in

CHECK_PORTABILITY_SKIP=	configure

BUILD_DEPENDS+=		yelp-tools-[0-9]*:../../textproc/yelp-tools

SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_FILES.python+=	modulesets/gnome-sysdeps-latest.modules
SUBST_SED.python+=	-e 's,python3.pc,python-${PYVERSSUFFIX}.pc,g'

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	/usr/bin/env *.*python*.*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	scripts/*.py scripts/jhbuild.in

PY_PATCHPLIST=		yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
