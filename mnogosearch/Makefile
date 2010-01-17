# $NetBSD: Makefile,v 1.13 2010/01/17 12:03:29 thomasklausner Exp $

DISTNAME=	mnogosearch-3.1.21
PKGREVISION=	3
CATEGORIES=	www databases
MASTER_SITES=	http://www.mnogosearch.org/Download/

MAINTAINER=	adrianp@stindustries.net
HOMEPAGE=	http://www.mnogosearch.org/
COMMENT=	Web search engine software for intranet and internet servers

GNU_CONFIGURE=		YES
USE_TOOLS+=		pax
PKG_DESTDIR_SUPPORT=	user-destdir

PKG_SYSCONFSUBDIR=	mnogosearch
MNOGOSEARCH_DATADIR?=	/var/mnogosearch
EGDIR=			${PREFIX}/share/examples/mnogosearch
DOCDIR=			${PREFIX}/share/doc/mnogosearch
BUILD_DEFS+=		MNOGOSEARCH_DATADIR USE_PGSQL USE_MYSQL
OWN_DIRS+=		${MNOGOSEARCH_DATADIR}
DB_TYPE=		--with-built-in

CONF_FILES=		${EGDIR}/indexer.conf-dist \
			${PKG_SYSCONFDIR}/indexer.conf
CONF_FILES+=		${EGDIR}/search.htm-dist \
			${PKG_SYSCONFDIR}/search.htm
CONF_FILES+=		${EGDIR}/spelld.conf-dist \
			${PKG_SYSCONFDIR}/spelld.conf

CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--localstatedir=${MNOGOSEARCH_DATADIR:Q}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.if defined(USE_MYSQL) && ${USE_MYSQL} == YES
.include "../../databases/mysql4-client/buildlink3.mk"
LIBS=			-Wl,-R${PREFIX}/lib/mysql
DB_TYPE=		--with-mysql=${BUILDLINK_PREFIX.mysql-client}
.endif

.if defined(USE_PGSQL) && ${USE_PGSQL} == YES
.include "../../mk/pgsql.buildlink3.mk"
LIBS=			-Wl,-R${PREFIX}/lib/postgresql
DB_TYPE=		--with-pgsql=${PGSQL_PREFIX}
.endif

CONFIGURE_ARGS+=	${DB_TYPE}

INSTALLATION_DIRS+=	${DOCDIR}/create

post-install:
	${INSTALL_DATA}	${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA}	${WRKSRC}/README ${DESTDIR}${DOCDIR}
	@${FIND} ${WRKSRC}/create -name CVS -type d | ${XARGS} ${RM} -rf
	cd ${WRKSRC}/create && pax -rw . ${DESTDIR}${DOCDIR}/create

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
