# $NetBSD: Makefile,v 1.1.1.1 2003/09/28 13:02:45 adrian_p Exp $

.include "Makefile.common"

COMMENT=	Prelude manager

USE_BUILDLINK2=		YES

CONFLICTS+=     prelude-mysql-manager-[0-9]*
CONFLICTS+=     prelude-pgsql-manager-[0-9]*

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --disable-pgsql

PLIST_SRC=      PLIST
PLIST_SRC+=     PLIST.base

.include "../../mk/bsd.pkg.mk"
