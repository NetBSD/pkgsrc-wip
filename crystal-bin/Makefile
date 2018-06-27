# $NetBSD$

DISTNAME=	crystal-0.25.0-1-${LOWER_OPSYS}-${MACHINE_ARCH}
PKGNAME=	crystal-bin-0.25.0
CATEGORIES=	lang
MASTER_SITES=	https://github.com/crystal-lang/crystal/releases/download/0.25.0/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://crystal-lang.org/
COMMENT=	Language with Ruby-like syntax and static type checking
LICENSE=	apache-2.0

ONLY_FOR_PLATFORM=	Darwin-*-x86_64

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/crystal-0.25.0-1

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/embedded/bin/crystal \
		${DESTDIR}${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
