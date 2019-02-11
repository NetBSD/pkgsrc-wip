# $NetBSD$

DISTNAME=	guile-git-0.2.0
CATEGORIES=	devel
MASTER_SITES=	https://gitlab.com/guile-git/guile-git/uploads/160f6a36c1be8d4fc1990a193081a04d/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/guile-git/guile-git/
COMMENT=	guile bindings of libgit2
LICENSE=	gnu-lgpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	automake autoconf autoreconf pkg-config
DEPENDS+=	guile-bytestructures>=1.0.5:../../wip/guile-bytestructures

pre-configure:
	export GUILE_LOAD_PATH="/usr/local/share/guile/site/2.2${GUILE_LOAD_PATH:+:}$GUILE_LOAD_PATH"
	export GUILE_LOAD_COMPILED_PATH="/usr/local/lib/guile/2.2/site-ccache${GUILE_LOAD_COMPILED_PATH:+:}$GUILE_COMPILED_LOAD_PATH"
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../devel/libgit2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
