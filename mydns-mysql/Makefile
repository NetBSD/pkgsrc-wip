# $NetBSD: Makefile,v 1.2 2005/10/29 16:50:59 minskim Exp $

PKGNAME=	${DISTNAME:S/-/-mysql-/}
COMMENT=	MySQL-based DNS server

CONFLICTS=	mydns-pgsql-[0-9]*

DISTINFO_FILE=	${.CURDIR}/../mydns-pgsql/distinfo
PATCHDIR=	${.CURDIR}/../mydns-pgsql/patches
FILESDIR=	${.CURDIR}/../mydns-pgsql/files

CONFIGURE_ARGS+=	--without-pgsql
CONFIGURE_ARGS+=	--with-mysql-lib=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-include=${BUILDLINK_PREFIX.mysql-client}/include/mysql

.include	"../../mk/mysql.buildlink3.mk"
.include	"../mydns-pgsql/Makefile.common"
