# $NetBSD$

GITHUB_PROJECT=	libgit2-glib
GITHUB_TAG=	v0.99.0.1
DISTNAME=	v0.99.0.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GNOME/libgit2-glib/
COMMENT=	Glib wrapper library around the libgit2 git access library
LICENSE=	gnu-lgpl-v2.1

WRKSRC=			${WRKDIR}/libgit2-glib-0.99.0.1
LD_LIBRARY_PATH=	${WRKSRC}/output/git2-glib
USE_PKGLOCALEDIR=	yes
USE_TOOLS=		pkg-config
USE_CMAKE=		yes
USE_LANGUAGES=		c c++

.include "../../devel/meson/build.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../devel/py-pygit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
