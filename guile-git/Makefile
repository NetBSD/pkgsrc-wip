# $NetBSD$

DISTNAME=	guile-git-0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/guile-git/guile-git/uploads/160f6a36c1be8d4fc1990a193081a04d/

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	Guile bindings of libgit2
LICENSE=	gnu-lgpl-v3
PKGREVISION=	1

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf pkg-config
DEPENDS+=	guile-bytestructures>=1.0.5:../../wip/guile-bytestructures

GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib
CONFIGURE_ENV+=		LIBGIT2_LIBDIR=${BUILDLINK_PREFIX.libgit2}/lib

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
