# $NetBSD$

DISTNAME=	crystal-0.26.1-1-${LOWER_OPSYS}-${MACHINE_ARCH}
PKGNAME=	${DISTNAME:S/crystal/crystal-bin/:C/-1-.*//}
CATEGORIES=	lang
MASTER_SITES=	https://github.com/crystal-lang/crystal/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://crystal-lang.org/
COMMENT=	Language with Ruby-like syntax and static type checking
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=		Darwin-*-x86_64
PYTHON_VERSIONS_ACCEPTED=	27

NO_BUILD=	yes
USE_TOOLS+=	bash:run pax
WRKSRC=		${WRKDIR}/crystal-${PKGVERSION_NOREV}-1

REPLACE_BASH=	bin/crystal
REPLACE_PYTHON=	embedded/bin/event_rpcgen.py

INSTALLATION_DIRS=	bin crystal

.include "../../lang/python/application.mk"

do-install:
	cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${PREFIX}/crystal
	ln -sf ${PREFIX}/crystal/bin/crystal ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
