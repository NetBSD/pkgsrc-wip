# $NetBSD: Makefile,v 1.6 2004/05/01 05:27:38 blef Exp $
#

DISTNAME=		smartmontools-5.30
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=smartmontools/}

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://smartmontools.sourceforge.net/
COMMENT=		Control and monitor storage systems using SMART

ONLY_FOR_PLATFORM=	FreeBSD-*-* Linux-*-* NetBSD-*-* SunOS-*-*
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/smartmontools
CONF_FILES=		${PREFIX}/share/doc/smartmontools/smartd.conf ${PKG_SYSCONFDIR}/smartd.conf
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/smartd ${PREFIX}/etc/rc.d/smartd
.endif

.include "../../mk/bsd.pkg.mk"
