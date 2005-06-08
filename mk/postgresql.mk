# $NetBSD: postgresql.mk,v 1.2 2005/06/08 15:47:01 dillo Exp $

# $Id: postgresql.mk,v 1.2 2005/06/08 15:47:01 dillo Exp $
#
# This is a copycat of databases/postgresql/Makefile.common, updated in 
# such way so it allows building 1st- and 3rd-party contrib packages 
# from PostgreSQL tree.
#
# Target location for it is databases/postgresql/ directory; Postgresql's
# Makefile.common could be updated so it uses values defined here.
#
# Yes, it's an ugly hack. But I have no idea how could I do this other way.
#
# It could propably be used for existing postgresql-* packages, which need
# extracted PostgreSQL sources and some extra DISTFILES
#
# Feel free to introduce changes / updates,
# 	-- dotz@irc.pl
#

PGSQL_MASTER_SITES=	http://www.postgresql.org/ftpsite/source/v${PGSQL_DIST_VERS}/ \
	       		ftp://ftp.postgresql.org/pub/source/v${PGSQL_DIST_VERS}/ \
       			ftp://ftp.de.postgresql.org/mirror/postgresql/source/v${PGSQL_DIST_VERS}/ \
       		       	ftp://gd.tuwien.ac.at/db/www.postgresql.org/pub/source/v${PGSQL_DIST_VERS}/ \
       	       		ftp://ftp.sunsite.auc.dk/mirrors/postgresql/source/v${PGSQL_DIST_VERS}/ \
       	       		ftp://ftp.jaist.ac.jp/pub/dbms/postgres95/source/v${PGSQL_DIST_VERS}/
		
PGSQL_DISTFILES=	postgresql-${PGSQL_DIST_VERS}.tar.gz

PGSQL_DISTINFO_FILE?=  	${.CURDIR}/../../databases/postgresql/distinfo
PGSQL_COMMON_FILESDIR?=	${.CURDIR}/../../databases/postgresql/files
PGSQL_PATCHDIR?=       	${.CURDIR}/../../databases/postgresql/patches

PGSQL_DIST_VERS?=      	7.4.1
PGSQL_BASE_VERS?=      	${DIST_VERS}

PGSQL_WRKSRC=		${WRKDIR}/postgresql-${PGSQL_DIST_VERS}
PGSQL_CONTRIBSRC=      	${WRKDIR}/postgresql-${PGSQL_DIST_VERS}/contrib

.include "../../mk/bsd.prefs.mk"

PGSQL_TEMPLATE.SunOS=		solaris
.if !defined(PGSQL_TEMPLATE.${OPSYS})
PGSQL_TEMPLATE.${OPSYS}=	${LOWER_OPSYS}
.endif

PGSQL_CONFIGURE_ARGS+=	--with-template="${PGSQL_TEMPLATE.${OPSYS}}"
PGSQL_CONFIGURE_ARGS+=	--without-readline
PGSQL_CONFIGURE_ARGS+=	--without-zlib

PGSQL_CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/postgresql
PGSQL_CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
PGSQL_CONFIGURE_ARGS+=	--with-htmldir=${PREFIX}/share/doc/html/postgresql

PGSQL_CONFIGURE_ARGS+=	--without-java
PGSQL_CONFIGURE_ARGS+=	--without-perl
PGSQL_CONFIGURE_ARGS+=	--without-python
PGSQL_CONFIGURE_ARGS+=	--without-tcl
PGSQL_CONFIGURE_ARGS+=	--without-tk

USE_TOOLS+=	autoconf

# Postgresql explicitly forbids any use of -ffast-math
CFLAGS:=		${CFLAGS:S/-ffast-math//}

postgresql-post-extract:
	if [ -d ${PGSQL_WRKSRC}/src ]; then					\
		${RM} -f ${PGSQL_WRKSRC}/src/Makefile.custom;			\
		${CP} -f ${PGSQL_COMMON_FILESDIR}/Makefile.custom		\
			${PGSQL_WRKSRC}/src/Makefile.custom;			\
	fi
	if [ -d ${PGSQL_WRKSRC}/src/interfaces/libpq ]; then			\
		${RM} -f ${PGSQL_WRKSRC}/src/interfaces/libpq/GNUmakefile;	\
		${CP} -f ${PGSQL_COMMON_FILESDIR}/GNUmakefile.libpq		\
			${PGSQL_WRKSRC}/src/interfaces/libpq/GNUmakefile;	\
	fi
	if [ -d ${PGSQL_WRKSRC}/src/interfaces/libpgtcl ]; then		\
		${RM} -f ${PGSQL_WRKSRC}/src/interfaces/libpgtcl/GNUmakefile;	\
		${CP} -f ${PGSQL_COMMON_FILESDIR}/GNUmakefile.libpgtcl	\
			${PGSQL_WRKSRC}/src/interfaces/libpgtcl/GNUmakefile;	\
	fi

postgresql-do-configure:
	cd ${PGSQL_WRKSRC} && autoconf && ${SETENV} \
		${PGSQL_CONFIGURE_ENV} ./configure \
		${PGSQL_CONFIGURE_ARGS}
