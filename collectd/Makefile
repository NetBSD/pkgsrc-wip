# $NetBSD: Makefile,v 1.2 2009/07/20 22:15:55 genolopolis Exp $
#

DISTNAME=	collectd-4.7.2
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
USE_TOOLS+= perl

PKGCONFIG_OVERRIDE+=	src/libcollectdclient/libcollectdclient.pc.in
USE_LANGUAGES= c c++
PKG_DESTDIR_SUPPORT=    user-destdir
CONFIGURE_ARGS+=	--with-perl-bindings='INSTALLDIRS=vendor'

#EGDIR=          ${PREFIX}/share/${PKGBASE}
#CONF_FILES=     ${EDGIR}/collectd.conf ${PKG_SYSCONFDIR}/collectd.conf

PERL5_CONFIGURE=	no
PERL5_PACKLIST=	auto/Collectd/.packlist

.include "../../devel/libltdl/convenience.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
