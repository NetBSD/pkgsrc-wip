# $NetBSD: Makefile,v 1.2 2005/09/27 16:10:01 thomasklausner Exp $
#

PKGNAME=	nagios-${DISTNAME}
DISTNAME=	nsca-${NSCAVERSION}
NSCAVERSION=	2.3
PKGREVISION=	# not defined
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
