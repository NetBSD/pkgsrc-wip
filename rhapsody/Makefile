# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:30 othyro Exp $
#

DISTNAME=		rhapsody_0.28b
PKGNAME=		rhapsody-0.28b
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=rhapsody/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://rhapsody.sourceforge.net
COMMENT=		IRC client for Unix operating systems
LICENSE=		gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-i ${PREFIX}/bin

# XXX : CC is forced to be /usr/bin/gcc. must be reported

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/rhapsody ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/rhapsody
	${INSTALL_DATA} ${WRKSRC}/help/*.hlp ${DESTDIR}${PREFIX}/share/rhapsody

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
