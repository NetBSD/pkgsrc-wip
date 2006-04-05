# $NetBSD: Makefile,v 1.3 2006/04/05 17:18:10 thomasklausner Exp $

DISTNAME=		nrpe-2.0
CATEGORIES=		net sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=nagios/}

MAINTAINER=		ura@jp.NetBSD.org
HOMEPAGE=		http://www.nagios.org/
COMMENT=		Nagios Remote Plugin Executor

DEPENDS+=		nagios-plugins>=1.3.1:../../net/nagios-plugins

GNU_CONFIGURE=		yes
USE_PERL5_BUILD=	yes
USE_REINPLACE=		yes

.include "Makefile.common"

RCD_SCRIPTS=		nrpe
PKG_GROUPS?=		${NRPE_GROUP}
PKG_USERS?=		${NRPE_USER}:${NRPE_GROUP}::Nagios\ Runtime\ User

INSTALLATION_DIRS=	sbin libexec/nagios share/examples/nagios

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nrpe ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/check_nrpe ${PREFIX}/libexec/nagios
	${INSTALL_DATA} ${WRKSRC}/nrpe.cfg ${PREFIX}/share/examples/nagios

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
