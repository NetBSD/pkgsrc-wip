# $NetBSD: Makefile,v 1.2 2004/05/10 01:20:36 blef Exp $

.include "../../wip/prelude-manager/Makefile.common"

PKGNAME=	${DISTNAME:S/-manger/-manager-mysql/}

COMMENT=	Prelude manager with MySQL support

CONFLICTS+=     prelude-manager-[0-9]*
CONFLICTS+=     prelude-manager-pgsql-[0-9]*

CONFIGURE_ARGS+=        --enable-mysql
CONFIGURE_ARGS+=        --disable-pgsql

PKGDIR=         ${.CURDIR}/../../wip/prelude-manager
FILESDIR=       ${PKGDIR}/files
PATCHDIR=       ${PKGDIR}/patches
DISTINFO_FILE=  ${PKGDIR}/distinfo
PLIST_SRC=      ${PKGDIR}/PLIST
PLIST_SRC+=     PLIST.mysql

.include "../../databases/mysql-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
