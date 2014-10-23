# $NetBSD: Makefile,v 1.5 2014/10/23 18:57:22 nros Exp $

DISTNAME=	qore-mysql-module-2.0.1
PKGREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	MySQL DB driver for Qore
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	native

INSTALL_TARGET=	install install-html-local

.include "options.mk"

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../wip/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
