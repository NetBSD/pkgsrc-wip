# $NetBSD: Makefile,v 1.3 2004/03/11 17:34:13 shattered Exp $
#

DISTNAME=		smartmontools-5.30
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* SunOS-*-*
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-docdir=${LOCALBASE}/share/doc/smartmontools
# CONFIGURE_ARGS+=	--enable-sample
CONF_FILES=		${LOCALBASE}/share/doc/smartmontools/smartd.conf ${LOCALBASE}/etc/smartd.conf
USE_GNU_TOOLS+=		make

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/smartd ${LOCALBASE}/etc/rc.d/smartd
.endif

.include "../../mk/bsd.pkg.mk"
