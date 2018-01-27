# $NetBSD: Makefile,v 1.2 2012/10/03 09:10:40 asau Exp $

DISTNAME=	libspt-1.1

CATEGORIES=	devel
MASTER_SITES=	http://www.j10n.org/libspt/

EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=	http://www.j10n.org/libspt/
COMMENT=	Provide unpriviliged secure pty
LICENSE=	2-clause-bsd

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

MAKE_ENV+=	SHELL=${SH}

SPECIAL_PERMS=	libexec/sptagent root wheel 4755

.include "../../mk/bsd.pkg.mk"
