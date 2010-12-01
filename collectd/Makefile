# $NetBSD: Makefile,v 1.7 2010/12/01 21:59:52 genolopolis Exp $
#

DISTNAME=	collectd-4.9.4
CATEGORIES=	net
MASTER_SITES=	http://collectd.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://collectd.org/
COMMENT=	The system statistics collection daemon
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	perl

PKGCONFIG_OVERRIDE+=	src/libcollectdclient/libcollectdclient.pc.in
USE_LANGUAGES=		c c++
PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-perl-bindings='INSTALLDIRS=vendor'
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/${PKGBASE}
CONFIGURE_ARGS+=	--with-included-ltdl	# see TODO

MAKE_DIRS+=		${PKG_SYSCONFDIR}/${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/collectd.conf ${PKG_SYSCONFDIR}/${PKGBASE}/collectd.conf
INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR}

PERL5_CONFIGURE=	no
PERL5_PACKLIST=	auto/Collectd/.packlist

PLIST_VARS+=	apache apcups ascent bind cpu csv curl dbi df disk
PLIST_VARS+=	dns email exec filecount hddtemp interface load
PLIST_VARS+=	logfile match-empty-counter match-hashed match-regex
PLIST_VARS+=	match-timediff match-value mbmon memcached memory
PLIST_VARS+=	multimeter mysql network nginx ntpd olsrd openvpn
PLIST_VARS+=	perl postgresql powerdns python rrdtool snmp swap
PLIST_VARS+=	syslog table tail target-notification target-replace
PLIST_VARS+=	target-scale target-set tcpconns teamspeak2 ted
PLIST_VARS+=	unixsock uptime users uuid write-http

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

#.include "../../devel/libltdl/convenience.mk"	# see TODO
.include "../../lang/perl5/module.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
