# $NetBSD$

DISTNAME=	OpenIPMI-2.0.29
CATEGORIES=	devel
MASTER_SITES=	https://newcontinuum.dl.sourceforge.net/project/openipmi/OpenIPMI%202.0%20Library/

MAINTAINER=	noahmehl@gmail.com
HOMEPAGE=	http://openipmi.sourceforge.net/
COMMENT=	User-level library that provides a higher-level abstraction of IPMI
LICENSE=	gnu-lgpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake perl pkg-config

LDFLAGS.NetBSD+=		-lexecinfo
BUILDLINK_TRANSFORM.NetBSD=	rm:-ldl

PKGCONFIG_OVERRIDE+=	OpenIPMI.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIcmdlang.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIglib.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIglib12.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIposix.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIpthread.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMItcl.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIui.pc.in
PKGCONFIG_OVERRIDE+=	OpenIPMIutils.pc.in

EGDIR=			${PREFIX}/share/examples/OpenIPMI
EGFILES=		lan.conf ipmisim1.emu

INSTALLATION_DIRS=	share/examples/OpenIPMI

.include "../../mk/bsd.prefs.mk"
post-install:
.for file in ${EGFILES}
	${MV} ${DESTDIR}${PREFIX}/etc/ipmi/${file} ${DESTDIR}${EGDIR}/${file}
.endfor

.include "options.mk"

.include "../../devel/popt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
