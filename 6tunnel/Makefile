# $NetBSD: Makefile,v 1.19 2025/04/21 21:01:38 wiz Exp $

DISTNAME=	6tunnel-0.14
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/wojtekka/6tunnel
COMMENT=	Tunnelling for applications that don't speak IPv6
LICENSE=	gnu-gpl-v2

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

GNU_CONFIGURE=	YES

.include "../../mk/bsd.pkg.mk"
