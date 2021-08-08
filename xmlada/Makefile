# $NetBSD$

VERSION=	21.0.0
DISTNAME=	xmlada-${VERSION}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
GITHUB_TAG=	v${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/xmlada/
COMMENT=	Adacore XML suite for the Ada language
LICENSE=	gnu-gpl-v3

# this will give circular dependency
DEPENDS+=	gprbuild-aux-[0-9]*:../../devel/gprbuild-aux
BROKEN=		"Circular dependency, xmlada -> gprbuild-aux -> xmlada"

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
