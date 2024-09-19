# $NetBSD: Makefile,v 1.2 2012/10/03 18:15:33 asau Exp $

DISTNAME=	nullpop-0.3
CATEGORIES=	mail
MASTER_SITES=	http://thewalter.net/stef/software/nullpop/
LICENSE=	gnu-gpl-v2

MAINTAINER=	shaun@inerd.com
HOMEPAGE=	http://thewalter.net/stef/software/nullpop/
COMMENT=	POP3 server that allows logins, but never returns any email

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--libexecdir="${PREFIX}/bin"

.include "../../mk/bsd.pkg.mk"
