# $NetBSD$

GITHUB_PROJECT=	clasp
DISTNAME=	clasp-3.3.5-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=potassco/}
GITHUB_RELEASE=	v3.3.5

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://potassco.org/clasp/
COMMENT=	Answer set solver for normal and disjunctive logic programs
LICENSE=	mit

WRKSRC=		${WRKDIR}/clasp-3.3.5

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../mk/bsd.pkg.mk"
