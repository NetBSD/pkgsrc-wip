# $NetBSD: Makefile,v 1.1 2013/06/03 02:20:00 phonohawk Exp $
#

DISTNAME=	tcptunnel-0.7
CATEGORIES=	net
MASTER_SITES=	http://www.vakuumverpackt.de/tcptunnel/

MAINTAINER=	pho@cielonegro.org
COMMENT=	Simple TCP port forwarder
LICENSE=	gnu-gpl-v2

do-configure:
	${RUN} cd ${WRKSRC} && \
		${SH} ./configure --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
