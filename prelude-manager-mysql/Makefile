# $NetBSD: Makefile,v 1.3 2004/10/29 06:01:23 dolecek Exp $

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

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
