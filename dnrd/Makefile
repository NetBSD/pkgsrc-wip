# $NetBSD: Makefile,v 1.1.1.1 2006/06/03 23:45:48 gschwarz Exp $

DISTNAME=	dnrd-2.20.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dnrd/}

MAINTAINER=	schwarz@NetBSD.org
HOMEPAGE=	http://dnrd.sourceforge.net/
COMMENT=	Dnrd is a caching forwarding DNS proxy

.include "options.mk"

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS=	sbin share/doc/dnrd

post-install:
		${RM} -f ${LOCALBASE}/share/doc/dnrd/README-cygwin \
			 ${LOCALBASE}/share/doc/dnrd/NEWS

.include "../../mk/bsd.pkg.mk"
