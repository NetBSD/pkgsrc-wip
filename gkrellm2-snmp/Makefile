# $NetBSD: Makefile,v 1.1.1.1 2003/04/16 12:41:56 cubidou Exp $
#

DISTNAME=	gkrellm_snmp-0.18
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

PATCH_SITES=		http://triq.net/gkrellm/
PATCHFILES=		gkrellm_snmp-0.18-gtk2.patch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent

USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
