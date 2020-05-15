# $NetBSD$

DISTNAME=	guix-1.1.0
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=guix/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://guix.gnu.org/
COMMENT=	Functional package manager
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoconf autoreconf pkg-config makeinfo gmake

# To boldly go where no one has gone before, id est the
# package hardcodes a list of supported architectures.
# To build it on anything else is a process of porting
# it to the platform.
CONFIGURE_ARGS+=	--with-courage

DEPENDS+=	guile-gcrypt>=0.1.0:../../devel/guile-gcrypt
DEPENDS+=	guile-json-[0-9]*:../../textproc/guile-json
DEPENDS+=	guile-sqlite3-[0-9]*:../../databases/guile-sqlite3

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../devel/argp/buildlink3.mk"
.include "../../lang/guile22/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
