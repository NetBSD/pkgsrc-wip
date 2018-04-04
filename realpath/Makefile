# $NetBSD: Makefile,v 1.42 2014/10/09 14:06:38 wiz Exp $

DISTNAME=	realpath-1.0
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://www.dragonflybsd.org/
COMMENT=	DragonFly BSD's version of realpath utility
LICENSE=	2-clause-bsd

CFLAGS+=	${CPPFLAGS} -DYYMAXDEPTH=300
MAKE_FLAGS+=	CC=${CC:Q} CFLAGS=${CFLAGS:M*:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-extract:
	@${CP} -R ${FILESDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/realpath ${DESTDIR}${PREFIX}/bin/realpath
	${INSTALL_MAN} ${WRKSRC}/realpath.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/realpath.1

.include "../../mk/bsd.pkg.mk"
