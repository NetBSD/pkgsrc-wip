# $NetBSD: Makefile,v 1.3 2006/12/26 21:09:32 gschwarz Exp $

DISTNAME=	dnrd-2.20.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnrd/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://dnrd.sourceforge.net/
COMMENT=	Dnrd is a caching forwarding DNS proxy

.include "options.mk"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "SunOS"
LIBS+=		-lrt	# for sem_*()
.endif

.if ${OPSYS} == "SunOS"
LIBS+=		-lsocket
LIBS+=		-lnsl	# for inet_ntoa()
LIBS+=		-lresolv	# for inet_aton()
.endif

INSTALLATION_DIRS=	sbin share/doc/dnrd

post-install:
		${RM} -f ${PREFIX}/share/doc/dnrd/README-cygwin \
			 ${PREFIX}/share/doc/dnrd/NEWS

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
