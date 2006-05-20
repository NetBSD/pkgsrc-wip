# $NetBSD: Makefile,v 1.2 2006/05/20 11:19:30 poppnk Exp $
#

PKGNAME=		rhapsody-0.28b
DISTNAME=		rhapsody_0.28b
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rhapsody/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://rhapsody.sourceforge.net
COMMENT=		IRC client for Unix operating systems.

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-i ${PREFIX}/bin

# XXX : CC is forced to be /usr/bin/gcc. must be reported

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rhapsody ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/rhapsody
	${INSTALL_DATA} ${WRKSRC}/help/*.hlp ${PREFIX}/share/rhapsody

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
