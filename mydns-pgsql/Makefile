# $NetBSD: Makefile,v 1.1.1.1 2005/09/09 12:38:12 ghen Exp $

PKGNAME=	${DISTNAME:S/-/-pgsql-/}
COMMENT=	PostgreSQL-based DNS server

CONFLICTS=	mydns-mysql-[0-9]*

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--with-pgsql-lib=${PREFIX}/lib
CONFIGURE_ARGS+=	--with-pgsql-include=${PREFIX}/include

.include	"../../mk/pgsql.buildlink3.mk"
.include	"Makefile.common"
