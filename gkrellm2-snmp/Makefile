# $NetBSD: Makefile,v 1.2 2003/12/31 10:55:23 cubidou Exp $
#

DISTNAME=	gkrellm_snmp-0.21
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://triq.net/gkrellm/

MAINTAINER=	cube@cubidou.net
HOMEPAGE=	http://triq.net/gkrellm_snmp.html
COMMENT=	GKrellM plugin to display values collected from a SNMP agent

USE_BUILDLINK2=	YES

.include "../../security/openssl/buildlink2.mk"
.include "../../wip/gkrellm2/buildlink2.mk"
.include "../../net/net-snmp/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
