# $NetBSD: Makefile,v 1.1.1.1 2004/12/11 22:28:09 cetrox Exp $
#

DISTNAME=		speedtouch-1.3.1
CATEGORIES=		net
MASTER_SITES=		http://mesh.dl.sourceforge.net/sourceforge/speedtouch/ \
			http://www.hystedjp.pwp.blueyonder.co.uk/speedtouch/latest/
DISTFILES=		speedtouch-1.3.1.tar.gz ZZZLboth.eni

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.xsproject.org/speedtouch/
COMMENT=		Alcatel Speedtouch 330 modem driver

DEPENDS+=               userppp>=001107:../../net/userppp

EXTRACT_ONLY=		speedtouch-1.3.1.tar.gz
WRKSRC=			${WRKDIR}/speedtouch-1.3.1
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
RCD_SCRIPTS=            adsl

post-install:
	${INSTALL_DATA} ${DISTDIR}/ZZZLboth.eni ${PREFIX}/libdata/alcaudsl.sys

.include "../../mk/bsd.pkg.mk"
