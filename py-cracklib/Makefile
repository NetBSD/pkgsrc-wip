# $NetBSD: Makefile,v 1.1 2013/09/17 13:49:55 thomasklausner Exp $

DISTNAME=	cracklib-2.9.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cracklib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/cracklib/
COMMENT=	Tool for preventing users from choosing bad passwords
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
PY_PATCHPLIST=		yes
# does not follow this convention
PY_PEP3147=		no

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
