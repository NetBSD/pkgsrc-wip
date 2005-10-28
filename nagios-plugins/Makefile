# $NetBSD: Makefile,v 1.8 2005/10/28 15:34:32 ykomatsu Exp $
#

CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagiosplug/}

MAINTAINER=     tech-pkg@NetBSD.org
HOMEPAGE=       http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins

.include "Makefile.common"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=      --with-df-command="/bin/df -Pklt nokernfs,procfs,fdesc"
.endif

DEPENDS+=	nagios-base>=1.0:../../wip/nagios-base

.if !exists(/usr/bin/ssh)
DEPENDS+=	{ssh{,6}-[0-9]*,openssh-[0-9]*}:../../security/ssh
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
