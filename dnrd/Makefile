# $NetBSD: Makefile,v 1.8 2010/09/05 09:19:17 gschwarz Exp $

DISTNAME=	dnrd-2.20.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnrd/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://dnrd.sourceforge.net/
COMMENT=	Dnrd is a caching forwarding DNS proxy
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

LIBS.NetBSD+=	-lrt	# for sem_*()
LIBS.SunOS+=	-lrt -lsocket -lnsl -lresolv	# for sem_*(), inet_ntoa(), inet_aton()

INSTALLATION_DIRS=	sbin share/doc/dnrd

post-install:
		${RM} -f ${DESTDIR}${PREFIX}/share/doc/dnrd/README-cygwin \
			 ${DESTDIR}${PREFIX}/share/doc/dnrd/NEWS

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
