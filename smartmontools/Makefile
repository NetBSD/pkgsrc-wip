# $NetBSD: Makefile,v 1.1.1.1 2003/12/25 23:03:52 shattered Exp $
#

DISTNAME=		smartmontools-5.26
CATEGORIES=		wip
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* SunOS-*-*
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-docdir=${LOCALBASE}/share/doc/smartmontools
CONF_FILES=		${LOCALBASE}/share/doc/smartmontools/smartd.conf ${LOCALBASE}/etc/smartd.conf

post-extract:
	${CP} ${FILESDIR}/os_netbsd.* ${WRKSRC}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/smartd ${LOCALBASE}/etc/rc.d/smartd
.endif

.include "../../mk/bsd.pkg.mk"
