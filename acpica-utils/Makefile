# $NetBSD: Makefile,v 1.2 2015/04/12 17:07:03 krytarowski Exp $
#

DISTNAME=	acpica-unix2-20150410
PKGNAME=	${DISTNAME:S/-unix2-/-utils-/}
CATEGORIES=	sysutils devel
MASTER_SITES=	https://acpica.org/sites/acpica/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.acpica.org/
COMMENT=	Intel ACPI CA Unix utilities
LICENSE=	modified-bsd OR gnu-gpl-v2

USE_TOOLS+=	bison flex gm4 gmake bash

.include "../../mk/bsd.pkg.mk"
