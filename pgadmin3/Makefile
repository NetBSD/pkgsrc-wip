# $NetBSD: Makefile,v 1.1.1.1 2003/11/30 01:36:37 mpasternak Exp $
#

DISTNAME=		pgadmin3-1.0.2
CATEGORIES=		databases
MASTER_SITES=		http://www.postgresql.org/ftpsite/pgadmin3/release/src/ \
			ftp://ftp.postgresql.org/pub/pgadmin3/release/src/ \
			ftp://ftp.de.postgresql.org/mirror/postgresql/pgadmin3/release/src/ \
			ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/pgadmin3/release/src/ \
			ftp://ftp.sunsite.auc.dk/mirrors/postgresql/pgadmin3/release/src/ \
			ftp://ftp6.pl.postgresql.org/pub/postgresql/pgadmin3/release/src/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://pgadmin.postgresql.org/
COMMENT=		GUI administration tool for PostgreSQL RDBMS

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-pgsql=${PREFIX} \
			--with-pgsql-include=${PREFIX}/include/postgresql \
			--with-wx=${PREFIX} \
			--with-pgsql=${PREFIX}

.include "../../wip/wxGTK2/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
