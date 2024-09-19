# $NetBSD$

DISTNAME=	spice-html5-0.1.7
CATEGORIES=	sysutils
MASTER_SITES=	https://people.freedesktop.org/~jwhite/spice-html5/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/
COMMENT=	Pure Javascript SPICE client
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

NO_BUILD=	YES

INSTALLATION_DIRS=	share/spice-html5

do-install:
	${RUN} cd ${WRKSRC} && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/spice-html5

.include "../../mk/bsd.pkg.mk"
