# $NetBSD$

DISTNAME=	guix-0.16.0
CATEGORIES=	misc
MASTER_SITES=	https://alpha.gnu.org/gnu/guix/

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/guix/
COMMENT=	Functional package manager
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		automake autoconf autoreconf pkg-config makeinfo

# To boldly go where no one has gone before, id est the
# package hardcodes a list of supported architectures.
# To build it on anything else is a process of porting
# it to the platform.
CONFIGURE_ARGS+=	--with-courage

# DEPENDS+=	guile-gcrypt>=0.1.0:../../wip/guile-git

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoreconf -I${PREFIX}/guile/2.2/share/aclocal -vif

.include "../../lang/guile22/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
