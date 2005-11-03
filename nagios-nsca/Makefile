# $NetBSD: Makefile,v 1.3 2005/11/03 14:52:17 rillig Exp $
#

PKGNAME=	nagios-${DISTNAME}
DISTNAME=	nsca-${NSCAVERSION}
NSCAVERSION=	2.3
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nagios.org/
COMMENT=	Remote/passive network service for nagios

.include "../nagios-base/Makefile.common"

.include "../../mk/bsd.prefs.mk"
.include "../../security/libmcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nsca ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/send_nsca ${PREFIX}/bin
	${INSTALL_DATA}    ${WRKSRC}/nsca.cfg ${PKG_SYSCONFDIR}
