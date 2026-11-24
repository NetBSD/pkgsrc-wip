# $NetBSD$

DISTNAME=		guile-gnutls-5.0.3
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_CODEBERG:=guile-gnutls/}
CODEBERG_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gitlab.com/gnutls/gnutls-guile/
COMMENT=		Guile bindings for the GnuTLS library
LICENSE=		gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
USE_TOOLS+=		pkg-config makeinfo gmake
INFO_FILES=		yes

WRKSRC=			${WRKDIR}/${PKGBASE}

.include "../../lang/guile30/module.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
