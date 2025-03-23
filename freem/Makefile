# $NetBSD$

DISTNAME=		freem-0.62.2
CATEGORIES=		lang
MASTER_SITES=		https://freem.coherent-logic.com/downloads/

MAINTAINER=		snw@coherent-logic.com
HOMEPAGE=		https://freem.coherent-logic.com/
COMMENT=		Implementation of the MUMPS programming language and database
LICENSE=		gnu-agpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}


.include "../../mk/bsd.pkg.mk"
.include "../../devel/readline/buildlink3.mk"
