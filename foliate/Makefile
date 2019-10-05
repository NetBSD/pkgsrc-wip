# $NetBSD$

DISTNAME=	foliate-1.5.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnfactotum/}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
COMMENT=	Simple and modern GTK eBook viewer
HOMEPAGE=	https://johnfactotum.github.io/foliate/
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gettext msgfmt msgmerge

BUILD_DEPENDS+=	${PYPKGPREFIX}-meson-[0-9]*:../../devel/py-meson
BUILD_DEPENDS+=	gjs>=1.52.0:../../wip/gjs
BUILD_DEPENDS+=	ninja-build-[0-9]*:../../devel/ninja-build

# XXX fails without GNU msgfmt
_TOOLS_USE_PKGSRC.msgfmt=	yes

REPLACE_PYTHON+=	${WRKSRC}/build-aux/meson/postinstall.py
REPLACE_PYTHON+=	${WRKSRC}/src/assets/KindleUnpack/compatibility_utils.py
REPLACE_PYTHON+=	${WRKSRC}/src/assets/KindleUnpack/mobi_split.py
REPLACE_PYTHON+=	${WRKSRC}/src/assets/KindleUnpack/mobiml2xhtml.py
REPLACE_PYTHON+=	${WRKSRC}/src/assets/KindleUnpack/unipath.py

GLIB_SCHEMAS=	com.github.johnfactotum.Foliate.gschema.xml

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} meson build --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ninja -C build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ninja -C build install

# Add options once the package is running correctly
#.include "options.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.24.0
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
