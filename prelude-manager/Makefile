# $NetBSD: Makefile,v 1.2 2004/05/10 01:20:35 blef Exp $

.include "Makefile.common"

COMMENT=	Prelude manager

CONFLICTS+=     prelude-mysql-manager-[0-9]*
CONFLICTS+=     prelude-pgsql-manager-[0-9]*

CONFIGURE_ARGS+=        --disable-mysql
CONFIGURE_ARGS+=        --disable-pgsql

PLIST_SRC=      PLIST
PLIST_SRC+=     PLIST.base

.include "../../mk/bsd.pkg.mk"
