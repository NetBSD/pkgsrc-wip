# $NetBSD$

DISTNAME=	gatus-5.36.0
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=TwiN/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	INSERT_YOUR_MAIL_ADDRESS_HERE # or use pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TwiN/gatus/
COMMENT=	TODO: Short description of the package
#LICENSE=	# TODO: (see mk/license.mk)

# Work around github tag/unpack-name confusion.
# \todo Hoist fix to github.mk.
WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
