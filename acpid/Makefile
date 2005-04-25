# $NetBSD: Makefile,v 1.3 2005/04/25 13:36:32 poppnk Exp $
#

DISTNAME=		acpid-1.0.4
CATEGORIES=		wip linux sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=acpid/}
PKGREVISION=		1

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://acpid.sourceforge.net/
COMMENT=		Linux ACPI event handler

EGDIR=			${PKG_SYSCONFDIR}/acpid ${PREFIX}/share/examples/acpid
USE_PKGINSTALL=		yes
RCD_SCRIPTS=		acpid

USE_GNU_TOOLS=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acpid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/acpi_listen ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/acpid.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/acpid
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/acpid/
	${CP} -rf ${WRKSRC}/samples/* ${PREFIX}/share/examples/acpid/

.include "../../mk/bsd.pkg.mk"
