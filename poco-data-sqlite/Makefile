# $NetBSD: Makefile,v 1.5 2011/01/23 15:19:31 thomasklausner Exp $
#

PKGNAME=	poco-data-sqlite-${POCO_VERSION}
CATEGORIES=	databases

COMMENT=	POCO C++ SQLite RDBMS Accessor libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../wip/poco/Makefile.common"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/MySQL,Data/ODBC,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples

USE_TOOLS+=	pax

INSTALLATION_DIRS=	include/Poco/Data/SQLite lib

do-build:
	cd ${WRKSRC} && ${TOOLS_GMAKE} POCO_BASE=${WRKSRC} -C Data/SQLite

do-install:
	# using the same logic as Poco's Makefile install target.
	cd ${WRKSRC} && find lib -name 'libPoco*' -type f -exec cp -f {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC} && find lib -name 'libPoco*' -type l -exec cp -Rf {} \
						    ${DESTDIR}${PREFIX}/lib \;
	cd ${WRKSRC}/Data/SQLite && \
	    ${PAX} -rw -v -pp include ${DESTDIR}${PREFIX}

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/poco-data/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
