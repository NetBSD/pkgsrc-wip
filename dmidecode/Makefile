# $NetBSD: Makefile,v 1.5 2004/05/12 15:11:20 shattered Exp $
#

DISTNAME=	dmidecode-2.4
CATEGORIES=	sysutils
MASTER_SITES=	http://savannah.gnu.org/download/dmidecode/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.nongnu.org/dmidecode/
COMMENT=	Print out DMI (SMBIOS) table in human-readable format

NO_BUILDLINK=	YES
USE_GNU_TOOLS+=		make
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86

.include "../../mk/bsd.pkg.mk"
