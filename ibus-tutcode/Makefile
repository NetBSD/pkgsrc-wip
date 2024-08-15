# $NetBSD$

VERSION=	1.0.2
DISTNAME=	ibus-tutcode-${VERSION}
CATEGORIES=	inputmethod
MASTER_SITES=	${MASTER_SITE_GITHUB:=deton/}
GITHUB_TAG=	ibus-tutcode-${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/deton/ibus-tutcode/
COMMENT=	Japanese TUT-Code input engine for IBus
LICENSE=	gnu-gpl-v2

DEPENDS+=	ibus-[0-9]*:../../inputmethod/ibus

WRKSRC=			${WRKDIR}/ibus-tutcode-ibus-tutcode-1.0.2
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c
USE_TOOLS+=		autoconf automake gmake

pre-configure:
	(cd ${WRKSRC}; ./autogen.sh --prefix ${PREFIX})

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
