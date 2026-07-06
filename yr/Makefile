# $NetBSD$

DISTNAME=	v1.1.0
PKGNAME=	yr-1.1.0
CATEGORIES=	misc
MASTER_SITES=	https://git.sr.ht/~timharek/yr/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~timharek/yr
COMMENT=	Get the weather delivered to your command-line
LICENSE=	gnu-gpl-v3

.include	"go-modules.mk"

WRKSRC=		${WRKDIR}/yr-v1.1.0
USE_LANGUAGES=	c

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
