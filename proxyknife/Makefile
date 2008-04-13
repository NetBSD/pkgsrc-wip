# $NetBSD: Makefile,v 1.4 2008/04/13 08:49:23 gschwarz Exp $

DISTNAME=	proxyknife-1.7
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GNU:=proxyknife/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/proxyknife/proxyknife.html
COMMENT=	Proxyknife is a tool to validate free proxies

GNU_CONFIGURE=	YES
INFO_FILES=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=	perl gmake
USE_FEATURES+=	snprintf

CONF_FILES=	${PREFIX}/share/proxyknife/doc/example/proxyknife.conf.example ${PKG_SYSCONFDIR}/proxyknife.conf

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
