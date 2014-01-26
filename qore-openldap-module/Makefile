# $NetBSD: Makefile,v 1.1 2014/01/26 21:08:58 nros Exp $

DISTNAME=	qore-openldap-module-1.0
CATEGORIES=	databases

.include "../../wip/qore/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Openldap module for Qore
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PTHREAD_OPTS+=	require

.include "../../wip/qore/options.mk"

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../wip/qore/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
