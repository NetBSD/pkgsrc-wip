# $NetBSD: Makefile,v 1.1.1.1 2005/01/03 19:52:33 poppnk Exp $
#

DISTNAME=		acpid-1.0.4
CATEGORIES=		wip linux sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=acpid/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://acpid.sourceforge.net/
COMMENT=		Linux ACPI event handler

USE_BUILDLINK3=		yes
USE_GNU_TOOLS=		make

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/acpid ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/acpi_listen ${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/acpid.8 ${PREFIX}/man/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/acpid/
	${CP} -rf ${WRKSRC}/samples/* ${PREFIX}/share/examples/acpid/

.include "../../mk/bsd.pkg.mk"
