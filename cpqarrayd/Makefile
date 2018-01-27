# $NetBSD: Makefile,v 1.1 2013/05/25 09:31:12 shattered Exp $
#

DISTNAME=	cpqarrayd-2.3
CATEGORIES=	sysutils
MASTER_SITES=	http://www.strocamp.net/opensource/compaq/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.strocamp.net/opensource/cpqarrayd.php
COMMENT=	Monitor HP SmartArray controllers
LICENSE=	gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-snmptrap

.include "../../mk/bsd.pkg.mk"
