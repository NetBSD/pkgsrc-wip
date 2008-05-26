# $NetBSD: Makefile,v 1.11 2008/05/26 13:59:43 tnn2 Exp $
#

DISTNAME=		acpid-1.0.4
CATEGORIES=		linux sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=acpid/}
PKGREVISION=		2

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://acpid.sourceforge.net/
COMMENT=		Linux ACPI event handler

ONLY_FOR_PLATFORM=	Linux-*-*

EGDIR=			${PREFIX}/share/examples/acpid
CONF_FILES+=		${EGDIR}/sample.conf ${PKG_SYSCONFDIR}/acpid/acpid.conf
RCD_SCRIPTS=		acpid

USE_TOOLS+=		gmake pax

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acpid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/acpi_listen ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/acpid.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/acpid
	cd ${WRKSRC}/samples/ && pax -wr * ${PREFIX}/share/examples/acpid/

.include "../../mk/bsd.pkg.mk"
