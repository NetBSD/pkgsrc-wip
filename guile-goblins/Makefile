# $NetBSD$

VERSION=	0.8
DISTNAME=	guile-goblins-v${VERSION}
PKGNAME=	${DISTNAME:S,-v,-,}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITLAB:=spritely/guile-goblins/-/archive/v${VERSION}/}

MAINTAINER=	gdt@lexort.com
HOMEPAGE=	https://spritely.institute/goblins/
COMMENT=	Distributed programming system with local transactions
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

USE_TOOLS+=     autoconf automake autoreconf pkg-config
GNU_CONFIGURE=	yes

pre-configure:
	set -e; cd ${WRKSRC} && ./bootstrap.sh

DEPENDS+=	guile-gcrypt-[0-9]*:../../devel/guile-gcrypt

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
