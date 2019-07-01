# $NetBSD: Makefile,v 1.5 2012/10/04 18:42:21 asau Exp $
#

DISTNAME=	Net-DBus-GLib-0.33.0
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DANBERR/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	https://metacpan.org/release/DANBERR/Net-DBus-GLib-0.33.0
COMMENT=	Perl extension for the DBus GLib bindings
#LICENSE=	# TODO: (see mk/license.mk)

USE_TOOLS+=	pkg-config

DEPENDS+=	p5-Net-DBus>=0.33.2:../../net/p5-Net-DBus
DEPENDS+=	p5-glib2-[0-9]*:../../devel/p5-glib2

PERL5_PACKLIST=	auto/Net/DBus/GLib/.packlist

.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
