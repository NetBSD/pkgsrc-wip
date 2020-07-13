# $NetBSD$

DISTNAME=	libgit2-glib-0.99.0.1
PKGNAME=	${PYPKGPREFIX}-libgit2-glib-0.99.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	libgit2-glib

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNOME/libgit2-glib/
COMMENT=	Glib wrapper library around the libgit2 git access library
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pygit2-[0-9]*:../../devel/py-pygit2

WRKSRC=			${WRKDIR}/${DISTNAME}

LD_LIBRARY_PATH=	${WRKSRC}/output/git2-glib
USE_TOOLS=		pkg-config
USE_LANGUAGES=		c c++
MESON_ARGS+=		-Dvapi=false

REPLACE_PYTHON+=	meson_python_compile.py
REPLACE_PYTHON+=	meson_vapi_link.py
REPLACE_PYTHON+=	tools/coverage.py
PY_PATCHPLIST=		yes

PKGCONFIG_OVERRIDE+=		output/meson-private/libgit2-glib-1.0.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
