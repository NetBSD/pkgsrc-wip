# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=	collectd-5.0.1
CATEGORIES=	wip
MASTER_SITES=	http://collectd.org/files/
CATEGORIES=     net

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://collectd.org/
COMMENT=	statistics collection daemon - base
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++

CONFIGURE_ARGS+=	--with-included-ltdl
CONFIGURE_ARGS+=	--disable-all-plugins
CONFIGURE_ARGS+=	--enable-csv
CONFIGURE_ARGS+=	--enable-exec
CONFIGURE_ARGS+=	--enable-logfile
CONFIGURE_ARGS+=	--enable-filecount
CONFIGURE_ARGS+=	--enable-df
CONFIGURE_ARGS+=	--enable-tail
CONFIGURE_ARGS+=	--enable-table
CONFIGURE_ARGS+=	--enable-syslog
CONFIGURE_ARGS+=	--enable-unixsock
CONFIGURE_ARGS+=	--enable-memcached
CONFIGURE_ARGS+=	--enable-network
CONFIGURE_ARGS+=	--enable-olsrd
CONFIGURE_ARGS+=	--enable-ntpd
CONFIGURE_ARGS+=	--enable-powerdns
CONFIGURE_ARGS+=	--enable-uptime
CONFIGURE_ARGS+=	--with-perl-bindings=no
CONFIGURE_ARGS+=	--with-libperl=no

PKGCONFIG_OVERRIDE+=	src/libcollectdclient/libcollectdclient.pc.in

.include "../../devel/libltdl/convenience.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../lang/perl5/dirs.mk"
