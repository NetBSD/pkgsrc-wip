# $NetBSD$

PKGNAME=		gnutls-${DISTNAME}
DISTNAME=		guile-3.7.11
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITLAB:=gnutls/}
GITLAB_PROJECT=		guile
GITLAB_RELEASE=		v${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gitlab.com/gnutls/gnutls-guile/
COMMENT=		Guile bindings for the GnuTLS library
LICENSE=		gnu-lgpl-v2.1 AND gnu-gpl-v3

GNU_CONFIGURE=		yes
GUILE_NEED_BOOTSTRAP=	yes
USE_TOOLS+=		pkg-config makeinfo
INFO_FILES=		yes
RELEASE_COMMIT=		1fbc46c7fda2bde6de583a5de241657d872aa006
WRKSRC=			${WRKDIR}/guile-v${PKGVERSION_NOREV}-${RELEASE_COMMIT}

.include "../../lang/guile30/module.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
