# $NetBSD: Makefile,v 1.2 2004/01/14 22:44:34 thomasklausner Exp $
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

.include "../../mk/bsd.prefs.mk"

.if !empty(WXGTK_USE_GTK1:M[Yy][Ee][Ss])
BROKEN=		Needs wxGTK to be compiled against GTK2 -- unset WXGTK_USE_GTK1 and reinstall wxGTK.
.endif

.include "../../x11/wxGTK/buildlink2.mk"
.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
