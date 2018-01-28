# $NetBSD: Makefile,v 1.9 2012/09/28 21:24:37 asau Exp $

DISTNAME=	dnrd-2.20.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnrd/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://dnrd.sourceforge.net/
COMMENT=	Dnrd is a caching forwarding DNS proxy
LICENSE=	gnu-gpl-v2

.include "options.mk"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

LIBS.NetBSD+=	-lrt	# for sem_*()
LIBS.SunOS+=	-lrt -lsocket -lnsl -lresolv	# for sem_*(), inet_ntoa(), inet_aton()

INSTALLATION_DIRS=	sbin share/doc/dnrd

post-install:
		${RM} -f ${DESTDIR}${PREFIX}/share/doc/dnrd/README-cygwin \
			 ${DESTDIR}${PREFIX}/share/doc/dnrd/NEWS

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
