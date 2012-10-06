# $NetBSD: Makefile,v 1.2 2012/10/06 17:55:25 asau Exp $
#

DISTNAME=	cdecimal-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	http://www.bytereef.org/software/mpdecimal/releases/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.bytereef.org/software/mpdecimal/releases/
COMMENT=	Fast arbitrary precision correctly-rounded decimal floating point arithmetic
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c99
PYDISTUTILSPKG=	yes

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
