# $NetBSD: Makefile,v 1.1 2014/02/05 16:30:30 nros Exp $

DISTNAME=	qore-sybase-modules-1.0.3
PKGNAME=	${DISTNAME:S/sybase-modules/freetds-module/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	Freetds DB driver for qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
PTHREAD_OPTS+=	require

.include "options.mk"

.include "../../databases/freetds/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
