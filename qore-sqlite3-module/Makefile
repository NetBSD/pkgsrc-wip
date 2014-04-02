# $NetBSD: Makefile,v 1.5 2014/04/02 20:06:48 nros Exp $

DISTNAME=	qore-sqlite3-module-1.0.1
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	SQLite module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

CONFIGURE_ARGS+=--with-sqlite3=${BUILDLINK_PREFIX.sqlite3}

INSTALLATION_DIRS+=     share/qore/docs/modules/sqlite3
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/sqlite3-module-doc.html \
		${DESTDIR}${PREFIX}/share/qore/docs/modules/sqlite3

.include "options.mk"

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
