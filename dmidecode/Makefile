# $NetBSD: Makefile,v 1.2 2004/01/25 02:12:01 grantbeattie Exp $
#

DISTNAME=	dmidecode-2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.gnu.org/download/dmidecode/dmidecode.pkg/2.2/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format

USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86

.include "../../mk/bsd.pkg.mk"
