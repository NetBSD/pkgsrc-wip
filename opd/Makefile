# $NetBSD: Makefile,v 1.3 2012/10/03 20:58:20 asau Exp $
#

DISTNAME=		opd-v0.2-2003-03-18
PKGNAME=		opd-0.2
CATEGORIES=		comms
MASTER_SITES=		http://oss.bdit.de/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://oss.bdit.de/opd.html
COMMENT=		OBEX PUSH daemon

WRKSRC=		${WRKDIR}/

# HaXoR trick to scape out of the pkgsrc jail ;)
#do-build:
#	cd ${WRKSRC} && env PATH=/usr/bin /usr/bin/gcc \
#	-L${PREFIX}/lib -I${PREFIX}/include *.c \
#	${CFLAGS} ${LDFLAGS} \
#	-lbluetooth -lopenobex \
#	 -o opd

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/opd ${DESTDIR}${PREFIX}/bin

.include "../../comms/openobex/buildlink3.mk"
.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
