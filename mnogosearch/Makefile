# $NetBSD: Makefile,v 1.1.1.1 2004/02/10 12:09:32 adrian_p Exp $

DISTNAME=	mnogosearch-3.1.21
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE= 	http://www.mnogosearch.org/
COMMENT=	Web search engine software for intranet and internet servers

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PKGINSTALL=         YES

PKG_SYSCONFSUBDIR=	mnogosearch
MNOGOSEARCH_DATADIR?=	/var/mnogosearch
EGDIR=			${PREFIX}/share/examples/mnogosearch
BUILD_DEFS+=		MNOGOSEARCH_DATADIR USE_PGSQL USE_MYSQL
OWN_DIRS+=		${MNOGOSEARCH_DATADIR}
DB_TYPE=		--with-built-in

CONF_FILES=		${EGDIR}/indexer.conf-dist \
			${PKG_SYSCONFDIR}/indexer.conf
CONF_FILES+=		${EGDIR}/search.htm-dist \
			${PKG_SYSCONFDIR}/search.htm
CONF_FILES+=		${EGDIR}/spelld.conf-dist \
			${PKG_SYSCONFDIR}/spelld.conf

CONFIGURE_ARGS+=        --with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--localstatedir=${MNOGOSEARCH_DATADIR}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
.include "../../databases/mysql4-client/buildlink2.mk"
LIBS=			-Wl,-R${PREFIX}/lib/mysql
DB_TYPE=		--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

.if defined(USE_PGSQL) && ${USE_PGSQL} == YES
.include "../../databases/postgresql-lib/buildlink2.mk"
LIBS=			-Wl,-R${PREFIX}/lib/postgresql
DB_TYPE=		--with-pgsql=${BUILDLINK_PREFIX.postgresql-lib}
.endif

CONFIGURE_ARGS+=	${DB_TYPE}

.include "../../security/openssl/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
