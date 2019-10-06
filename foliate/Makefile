# $NetBSD$

DISTNAME=	foliate-1.5.3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnfactotum/}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
COMMENT=	Simple and modern GTK eBook viewer
HOMEPAGE=	https://johnfactotum.github.io/foliate/
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext

BUILD_DEPENDS+=	gjs>=1.52.0:../../wip/gjs

# XXX fails without GNU msgfmt
_TOOLS_USE_PKGSRC.msgfmt=	yes

REPLACE_PYTHON+=	${WRKSRC}/build-aux/meson/postinstall.py
REPLACE_PYTHON+=	${WRKSRC}/src/assets/KindleUnpack/*.py

GLIB_SCHEMAS=	com.github.johnfactotum.Foliate.gschema.xml

.include "../../devel/py-meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.24.0
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
