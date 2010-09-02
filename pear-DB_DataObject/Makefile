# $NetBSD: Makefile,v 1.2 2010/09/02 00:40:29 obache Exp $

DISTNAME=	DB_DataObject-1.8.5
CATEGORIES=	databases

MAINTAINER=	loic-hoguin@users.sourceforge.net
COMMENT=	SQL Builder, Object Interface to Database Tables

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Date>=1.4.7:../../time/pear-Date
DEPENDS+=	${PHP_PKG_PREFIX}-pear-DB>=1.7.0:../../databases/pear-DB

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
