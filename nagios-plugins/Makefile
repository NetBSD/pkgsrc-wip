# $NetBSD: Makefile,v 1.6 2005/08/04 18:25:00 scott8586 Exp $
#

PKGREVISION=	# not defined
CATEGORIES=	net sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=nagiosplug/}

MAINTAINER=     murray@river-styx.org
HOMEPAGE=       http://sourceforge.net/projects/nagiosplug/
COMMENT=	Nagios plugins

.include "../../wip/nagios-plugins/Makefile.common"

.include "../../mk/bsd.prefs.mk"

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
