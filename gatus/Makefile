# $NetBSD$

DISTNAME=	gatus-5.36.0
CATEGORIES=	systuils
MASTER_SITES=	${MASTER_SITE_GITHUB:=TwiN/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TwiN/gatus/
COMMENT=	Gatus is a developer-oriented health dashboard that gives you the ability to monitor your services
LICENSE=	apache-2.0

# Work around github tag/unpack-name confusion.
# \todo Hoist fix to github.mk.
WRKSRC=	${WRKDIR}/${DISTNAME}

USE_LANGUAGES=	c

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
