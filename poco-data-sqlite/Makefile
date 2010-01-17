# $NetBSD: Makefile,v 1.2 2010/01/17 12:03:30 thomasklausner Exp $
#

DISTNAME=	poco-1.3.5-all
PKGNAME=	poco-data-sqlite-1.3.5
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=poco/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.pocoproject.org/
COMMENT=	POCO C++ SQLite RDBMS Accessor libraries
# LICENSE=	boost

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

PATCHDIR=	${.CURDIR}/../../wip/poco/patches
DISTINFO_FILE=	${.CURDIR}/../../wip/poco/distinfo

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--omit=Data/MySQL,Data/ODBC,Zip,XML
CONFIGURE_ARGS+=	--omit=Foundation,Net,NetSSL_OpenSSL
CONFIGURE_ARGS+=	--no-tests
CONFIGURE_ARGS+=	--no-samples

.if !empty(OPSYS:M*BSD)
CONFIGURE_ARGS+=	--config=FreeBSD
.endif

.if ${OPSYS} == "NetBSD"
# NetBSD doesn't have fenv.h. We should add one.
CONFIGURE_ARGS+=	--no-fpenvironment
.endif

INSTALLATION_DIRS=	include/Poco/Data/SQLite lib
do-build:
	cd $(WRKSRC) && $(TOOLS_GMAKE) POCO_BASE=$(WRKSRC) -C Data/SQLite

do-install:
	# using the same logic as Poco's Makefile install target.
	cd $(WRKSRC) && find lib -name 'libPoco*' -type f -exec cp -f {} \
						    $(DESTDIR)$(PREFIX)/lib \;
	cd $(WRKSRC) && find lib -name 'libPoco*' -type l -exec cp -Rf {} \
						    $(DESTDIR)$(PREFIX)/lib \;
	cd $(WRKSRC)/Data/SQLite && \
	    pax -rw -v -pe include $(DESTDIR)$(PREFIX)

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../wip/poco-data/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
