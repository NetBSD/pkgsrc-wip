# $NetBSD $

DISTNAME=		slony1-1.1.2
CATEGORIES=		databases
MASTER_SITES=		http://developer.postgresql.org/~wieck/slony1/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-wip-discuss@lists.sourceforge.net
HOMEPAGE=		http://www.slony.info/
COMMENT=		Async Replication System for PostgreSQL

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-pgconfigdir=${LOCALBASE}/bin \
			--with-pgbindir=${LOCALBASE}/bin \
			--with-pgincludedir=${LOCALBASE}/include/postgresql \
			--with-pgincludeserverdir=${LOCALBASE}/include/postgresql/server \
			--with-pglibdir=${LOCALBASE}/lib\
			--with-pgpkglibdir=${LOCALBASE}/lib/postgresql \
			--with-pgsharedir=${LOCALBASE}/share/postgresql

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT ${WRKSRC}/INSTALL ${WRKSRC}/SAMPLE \
		${WRKSRC}/README ${WRKSRC}/HISTORY-1.1 ${WRKSRC}/UPGRADING \
		${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/share/slon.conf-sample ${PREFIX}/etc/

.include "../../databases/postgresql80-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
