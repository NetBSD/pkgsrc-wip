# $NetBSD$

DISTNAME=	cracklib-2.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cracklib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/cracklib/
COMMENT=	Tool for preventing users from choosing bad passwords
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PY_PATCHPLIST=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
