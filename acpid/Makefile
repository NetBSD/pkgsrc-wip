# $NetBSD: Makefile,v 1.14 2012/11/25 23:32:07 othyro Exp $
#

DISTNAME=		acpid-1.0.4
PKGREVISION=		2
CATEGORIES=		linux sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=acpid/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://acpid.sourceforge.net/
COMMENT=		Linux ACPI event handler
LICENSE=		gnu-gpl-v2

ONLY_FOR_PLATFORM=	Linux-*-*

EGDIR=			${PREFIX}/share/examples/acpid
CONF_FILES+=		${EGDIR}/sample.conf ${PKG_SYSCONFDIR}/acpid/acpid.conf
RCD_SCRIPTS=		acpid
INSTALLATION_DIRS+=	share/examples/acpid

USE_TOOLS+=		gmake pax

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acpid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/acpi_listen ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/acpid.8 ${PREFIX}/${PKGMANDIR}/man8/
	cd ${WRKSRC}/samples/ && pax -wr * ${PREFIX}/share/examples/acpid/

.include "../../mk/bsd.pkg.mk"
