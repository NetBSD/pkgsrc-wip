# $NetBSD: Makefile,v 1.1.1.1 2004/06/09 21:36:26 jeremy-c-reed Exp $
#

DISTNAME=		hotplug-2002_04_01
PKGNAME=		${DISTNAME:S/_//}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=linux-hotplug/}	\
			ftp://ftp.kernel.org/pub/linux/utils/kernel/hotplug/
# XXX we should have a MASTER_SITE_LINUX definition

MAINTAINER=		reed@reedmedia.net
HOMEPAGE=		http://linux-hotplug.sourceforge.net/
COMMENT=		Hardware autoconfiguration for Linux

USE_BUILDLINK3=		yes

.include "../../mk/bsd.pkg.mk"
